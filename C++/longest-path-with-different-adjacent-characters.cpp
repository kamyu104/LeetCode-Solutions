// Time:  O(n)
// Space: O(w)

// tree, bfs, topological sort
class Solution {
public:
    int longestPath(vector<int>& parent, string s) {    
        vector<vector<int>> adj(size(s));
        vector<int> in_degree(size(s));
        for (int i = 1; i < size(parent); ++i) {
            adj[i].emplace_back(parent[i]);
            ++in_degree[parent[i]];
        }
        
        const auto& topological_sort = [&s, &adj](vector<int> *in_degree) {
            int result = 1;
            unordered_map<int, vector<int>> top2;
            vector<pair<int, int>> q;
            for (int i = 0; i < size(*in_degree); ++i) {
                if (!(*in_degree)[i]) {
                    q.emplace_back(i, 1);
                }
            }
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (const auto& [u, l] : q) {
                    for (const auto& v : adj[u]) {
                        if (!top2.count(v)) {
                            top2[v] = vector<int>(2);
                        }
                        if (s[v] != s[u]) {
                            if (l > top2[v][0]) {
                                top2[v][1] = top2[v][0];
                                top2[v][0] = l;
                            } else if (l > top2[v][1]) {
                                top2[v][1] = l;
                            }
                        }
                        if (!--(*in_degree)[v]) {
                            new_q.emplace_back(v, top2[v][0] + 1);
                            result = max(result, top2[v][0] + top2[v][1] + 1);
                            top2.erase(v);
                        }
                    }
                }
                q = move(new_q);
            }
            return result;
        };
        return topological_sort(&in_degree);
    }
};

// Time:  O(n)
// Space: O(h)
// tree, dfs
class Solution2 {
public:
    int longestPath(vector<int>& parent, string s) {    
        vector<vector<int>> adj(size(s));
        for (int i = 1; i < size(parent); ++i) {
            adj[parent[i]].emplace_back(i);
        }
        
        const auto& iter_dfs = [&s, &adj]() {
            using RET = shared_ptr<int>;
            using TOP2 = shared_ptr<pair<int, int>>;
            int result = 0;
            vector<tuple<int, int, int, TOP2, RET, RET>> stk;
            stk.emplace_back(1, 0, -1, nullptr, nullptr, make_shared<int>());
            while (!empty(stk)) {
                auto [step, u, i, top2, ret2, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    auto top2 = make_shared<pair<int, int>>(0, 0);
                    stk.emplace_back(4, u, -1, top2, nullptr, ret);
                    stk.emplace_back(2, u, 0, top2, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    auto ret2 = make_shared<int>();
                    stk.emplace_back(3, u, i, top2, ret2, nullptr);
                    stk.emplace_back(1, adj[u][i], -1, nullptr, nullptr, ret2); 
                } else if (step == 3) {
                    if (s[adj[u][i]] != s[u]) {
                        if (*ret2 > top2->first) {
                            top2->second = top2->first;
                            top2->first = *ret2;
                        } else if (*ret2 > top2->second) {
                            top2->second = *ret2;
                        }
                    }
                    stk.emplace_back(2, u, i + 1, top2, nullptr, ret);
                } else if (step == 4) {
                    result = max(result, top2->first + top2->second + 1);
                    *ret = top2->first +1;
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(h)
// tree, dfs
class Solution3 {
public:
    int longestPath(vector<int>& parent, string s) {    
        vector<vector<int>> adj(size(s));
        for (int i = 1; i < size(parent); ++i) {
            adj[parent[i]].emplace_back(i);
        }
        
        function<int(int, int*)> dfs = [&dfs, &s, &adj](int u, int *result) {
            vector<int> top2(2);
            for (const auto& v : adj[u]) {
                const auto& l = dfs(v, result);
                if (s[v] == s[u]) {
                    continue;
                }
                if (l > top2[0]) {
                    top2[1] = top2[0];
                    top2[0] = l;
                } else if (l > top2[1]) {
                    top2[1] = l;
                }
            }
            *result = max(*result, top2[0] + top2[1] + 1);
            return top2[0] + 1;
        };

        int result = 0;
        dfs(0, &result);
        return result;
    }
};
