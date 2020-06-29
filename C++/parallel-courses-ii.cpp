// Time:  O((n * C(c, min(c, k))) * 2^n)
// Space: O(2^n)

// concise dp solution
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> reqs(n);
        for (const auto& d : dependencies) {
            reqs[d[1] - 1] |= 1 << (d[0] - 1);
        }
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for (int mask = 0; mask < dp.size(); ++mask) {
            vector<int> candidates;
            for (int v = 0; v < n; ++v) {
                if ((mask & (1 << v)) == 0 && (mask & reqs[v]) == reqs[v]) {
                    candidates.emplace_back(v);
                }
            }
            const auto r = min(int(candidates.size()), k);
            combinations(candidates.size(), min(int(candidates.size()), k), 
                         [&dp, &mask, &candidates](const vector<int>& idxs) {
                             auto new_mask = mask;
                             new_mask |= accumulate(cbegin(idxs), cend(idxs), 0,
                                                    [&candidates](const auto& a, const auto& b) {
                                                        return a | (1 << candidates[b]);
                                                    });
                             dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
                         });
        }
        return dp.back();
    }

private:
    void combinations(int n, int k, const function<void (const vector<int>&)>& callback) {
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };
    
        vector<int> idxs(k);
        iota(begin(idxs), end(idxs), 0);
        callback(idxs);
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            callback(idxs);
        }
    }
};

// Time:  O((n * C(c, min(c, k))) * 2^n)
// Space: O(2^n)
// embedded combination dp solution
class Solution2 {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        static const auto& choice_mask =
            [](const auto& nums, const auto& idxs) {
                return accumulate(cbegin(idxs), cend(idxs), 0,
                                  [&nums](const auto& a, const auto& b) {
                                      return a | (1 << nums[b]);
                                  });
            };
        static const auto& next_pos =
            [](const auto& n, const auto& r, const auto& idxs) {
                int i = r - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - r) {
                        break;
                    }
                }
                return i;
            };

        vector<int> reqs(n);
        for (const auto& d : dependencies) {
            reqs[d[1] - 1] |= 1 << (d[0] - 1);
        }
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for (int mask = 0; mask < dp.size(); ++mask) {
            vector<int> candidates;
            for (int v = 0; v < n; ++v) {
                if ((mask & (1 << v)) == 0 && (mask & reqs[v]) == reqs[v]) {
                    candidates.emplace_back(v);
                }
            }
            const auto r = min(int(candidates.size()), k);
            vector<int> idxs(r);
            iota(begin(idxs), end(idxs), 0);
            const auto& new_mask = (mask | choice_mask(candidates, idxs));
            dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
            for (int i; (i = next_pos(candidates.size(), r, idxs)) >= 0;) {
                ++idxs[i];
                for (int j = i + 1; j < k; ++j) {
                    idxs[j] = idxs[j - 1] + 1;
                }
                const auto& new_mask = (mask | choice_mask(candidates, idxs));
                dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
            }
        }
        return dp.back();
    }
};

// Time:  O(nlogn + e), e is the number of edges in graph
// Space: O(n + e)
// wrong greedy solution
// since the priority of courses are hard to decide especially for those courses with zero indegrees are of the same outdegrees and depths
// e.x.
// 9
// [[1,4],[1,5],[3,5],[3,6],[2,6],[2,7],[8,4],[8,5],[9,6],[9,7]]
// 3
class Solution_WA {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        unordered_map<int, vector<int>> graph;
        vector<int> degrees(n);
        for (const auto &d: dependencies) {
            graph[d[0] - 1].emplace_back(d[1] - 1);
            ++degrees[d[1] - 1];
        }
        vector<int> depths(n, -1);
        for (int i = 0; i < n; ++i) {
            dfs(graph, i, &depths);
        }
        priority_queue<pair<int, int>> max_heap;
        for (int i = 0; i < n; ++i) {
            if (!degrees[i]) {
                max_heap.emplace(depths[i], i);
            }
        }
        int result = 0;
        while (!max_heap.empty()) {
            vector<int> new_q;
            for (int i = 0; !max_heap.empty() && i < k; ++i) {
                const auto [depth, node] = max_heap.top(); max_heap.pop();
                for (const auto& child : graph[node]) {
                    if (!--degrees[child]) {
                        new_q.emplace_back(child);
                    }
                }
            }
            ++result;
            for (const auto& node : new_q) {
                max_heap.emplace(depths[node], node);
            }
        }
        return result;
    }

private:
    int dfs(const unordered_map<int, vector<int>> &graph,
            int i, vector<int> *depths) {
        if ((*depths)[i] == -1) {
            int depth = 0;
            if (graph.count(i)) {
                for (const auto& child : graph.at(i)) {
                    depth = max(depth, dfs(graph, child, depths));
                }
            }
            (*depths)[i] = depth + 1;
        }
        return (*depths)[i];
    }
};
