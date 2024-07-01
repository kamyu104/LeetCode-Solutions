// Time:  O(n + m)
// Space: O(n + m)

// iterative dfs, tree diameter
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / 2;
        };

        const auto& tree_diameter = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            int result = 0;
            const auto& iter_dfs = [&]() {
                int result = 0;
                using RET = int;
                RET ret{};
                vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &ret}};
                while (!empty(stk)) {
                    const auto [step, u, p, ret2, ret] = stk.back(); stk.pop_back();
                    if (step == 1) {
                        for (const auto& v : adj[u]) {
                            if (v == p) {
                                continue;
                            }
                            const auto& ret2 = make_shared<RET>();
                            stk.emplace_back(2, -2, -2, ret2, ret);
                            stk.emplace_back(1, v, u, nullptr, ret2.get());
                        }
                    } else if (step == 2) {
                        result = max(result, *ret + (*ret2 + 1));
                        *ret = max(*ret, *ret2 + 1);
                    }
                }
                return result;
            };

            return iter_dfs();
        };

        const int d1 = tree_diameter(edges1);
        const int d2 = tree_diameter(edges2);
        return max({ceil_divide(d1, 2) + 1 + ceil_divide(d2, 2), d1, d2});
    }
};


// Time:  O(n + m)
// Space: O(n + m)
// dfs, tree diameter
class Solution2 {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / 2;
        };

        const auto& tree_diameter = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            int result = 0;
            const function<int (int, int)> dfs = [&](int u, int p) {
                int mx = 0;
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    const int curr = dfs(v, u);
                    result = max(result, mx + (curr + 1));
                    mx = max(mx, curr + 1);
                }
                return mx;
            };

            dfs(0, -1);
            return result;
        };

        const int d1 = tree_diameter(edges1);
        const int d2 = tree_diameter(edges2);
        return max({ceil_divide(d1, 2) + 1 + ceil_divide(d2, 2), d1, d2});
    }
};

// Time:  O(n + m)
// Space: O(n + m)
// bfs, tree dp, tree diameter
class Solution3 {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / 2;
        };

        const auto& tree_diameter = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            int result = 0;
            const auto& bfs = [&]() {
                int result = 0;
                vector<int> dp(size(adj));
                vector<int> degree(size(adj));
                vector<int> q;
                for (int u = 0; u < size(adj); ++u) {
                    degree[u] = size(adj[u]);
                    if (degree[u] == 1) {
                        q.emplace_back(u);
                    }
                }
                while (!empty(q)) {
                    vector<int> new_q;
                    for (const auto& u : q) {
                        if (degree[u] == 0) {
                            continue;
                        }
                        --degree[u];
                        for (const auto& v : adj[u]) {
                            if (degree[v] == 0) {
                                continue;
                            }
                            result = max(result, dp[v] + (dp[u] + 1));
                            dp[v] = max(dp[v], dp[u] + 1);
                            if (--degree[v] == 1) {
                                new_q.emplace_back(v);
                            }
                        }
                    }
                    q = move(new_q);
                }
                return result;
            };

            return bfs();
        };

        const int d1 = tree_diameter(edges1);
        const int d2 = tree_diameter(edges2);
        return max({ceil_divide(d1, 2) + 1 + ceil_divide(d2, 2), d1, d2});
    }
};

// Time:  O(n + m)
// Space: O(n + m)
// bfs, tree diameter
class Solution4 {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / 2;
        };

        const auto& tree_diameter = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            int result = 0;
            const auto& bfs = [&](int root) {
                int d = -1, new_root = -1;
                vector<bool> lookup(size(adj));
                lookup[root] = true;
                vector<int> q = {root};
                while (!empty(q)) {
                    ++d;
                    new_root = q[0];
                    vector<int> new_q;
                    for (const auto& u : q) {
                        for (const auto& v : adj[u]) {
                            if (lookup[v]) {
                                continue;
                            }
                            lookup[v] = true;
                            new_q.emplace_back(v);
                        }
                    }
                    q = move(new_q);
                }
                return pair(d, new_root);
            };

            const auto& [_, root] = bfs(0);
            const auto& [d, __] = bfs(root);
            return d;
        };

        const int d1 = tree_diameter(edges1);
        const int d2 = tree_diameter(edges2);
        return max({ceil_divide(d1, 2) + 1 + ceil_divide(d2, 2), d1, d2});
    }
};
