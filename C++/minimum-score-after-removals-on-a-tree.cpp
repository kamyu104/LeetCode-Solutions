// Time:  O(n^2)
// Space: O(n)

// dfs with stack
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int> left(size(nums)), right(size(nums));
        const auto& is_ancestor = [&](int a, int b) {
            return left[a] <= left[b] && right[b] <= right[a];
        };

        const auto& iter_dfs = [&]() {
            int cnt = 0;
            vector<tuple<int, int, int>> stk;
            stk.emplace_back(1, 0, -1);
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    left[u] = cnt++;
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        nums[u] ^= nums[v];
                    }
                    right[u] = cnt;
                }
            }
        };

        iter_dfs();
        int result = numeric_limits<int>::max();
        for (int i = 1; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                int a, b, c;
                if (is_ancestor(i, j)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i], nums[i] ^ nums[j], nums[j]);
                } else if (is_ancestor(j, i)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[j], nums[j] ^ nums[i], nums[i]);
                } else {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i] ^ nums[j], nums[i], nums[j]);
                }
                result = min(result, max({a, b, c}) - min({a, b, c}));
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dfs with recursion
class Solution2 {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int cnt = 0;
        vector<int> left(size(nums)), right(size(nums));
        const auto& is_ancestor = [&](int a, int b) {
            return left[a] <= left[b] && right[b] <= right[a];
        };

        function<void(int, int)> dfs = [&](int u, int p) {
            left[u] = cnt++;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                nums[u] ^= nums[v];
            }
            right[u] = cnt;
        };

        dfs(0, -1);
        int result = numeric_limits<int>::max();
        for (int i = 1; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                int a, b, c;
                if (is_ancestor(i, j)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i], nums[i] ^ nums[j], nums[j]);
                } else if (is_ancestor(j, i)) {
                    tie(a, b, c) = tuple(nums[0] ^ nums[j], nums[j] ^ nums[i], nums[i]);
                } else {
                    tie(a, b, c) = tuple(nums[0] ^ nums[i] ^ nums[j], nums[i], nums[j]);
                }
                result = min(result, max({a, b, c}) - min({a, b, c}));
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dfs with recursion
class Solution3 {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        function<int(int, int, vector<int> *)> dfs = [&](int u, int p, vector<int> *result) {
            int total = nums[u];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                total ^= dfs(v, u, result);
            }
            result->emplace_back(total);
            return total;
        };
        
        const int total = accumulate(cbegin(nums), cend(nums), 0,
                                     [](int x, int y) {
                                         return x ^ y;
                                     });
        int result = numeric_limits<int>::max();
        for (const auto& e : edges) {
            vector<vector<int>> xors(2);
            dfs(e[0], e[1], &xors[0]);
            dfs(e[1], e[0], &xors[1]);
            for (auto& candidates : xors) {
                const int total2 = candidates.back(); candidates.pop_back();
                for (const auto& x : candidates) {
                    const auto& [a, b, c] = tuple(total ^ total2, x, total2 ^ x);
                    result = min(result, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dfs with stack
class Solution4_TLE {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&](int u, int p, vector<int> *result) {
            using RET = int;
            RET ret = 0;
            vector<tuple<int, int, int, shared_ptr<vector<shared_ptr<RET>>>, RET *>> stk;
            stk.emplace_back(1, u, p, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, u, p, new_rets, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    auto new_rets = make_shared<vector<shared_ptr<RET>>>();
                    stk.emplace_back(2, u, p, new_rets, ret);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_rets->emplace_back(make_shared<RET>());
                        stk.emplace_back(1, v, u, nullptr, new_rets->back().get());
                    }
                } else if (step == 2) {
                    *ret = nums[u];
                    for (const auto& x : *new_rets) {
                        *ret ^= *x;
                    }
                    result->emplace_back(*ret);
                }
            }
        };
        
        const int total = accumulate(cbegin(nums), cend(nums), 0,
                                     [](int x, int y) {
                                         return x ^ y;
                                     });
        int result = numeric_limits<int>::max();
        for (const auto& e : edges) {
            vector<vector<int>> xors(2);
            iter_dfs(e[0], e[1], &xors[0]);
            iter_dfs(e[1], e[0], &xors[1]);
            for (auto& candidates : xors) {
                const int total2 = candidates.back(); candidates.pop_back();
                for (const auto& x : candidates) {
                    const auto& [a, b, c] = tuple(total ^ total2, x, total2 ^ x);
                    result = min(result, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return result;
    }
};
