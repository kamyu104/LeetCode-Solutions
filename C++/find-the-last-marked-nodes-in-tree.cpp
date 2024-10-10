// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&](int root) {
            int new_root = -1;
            vector<int> dist(size(adj), -1);
            dist[root] = 0;
            vector<int> q = {root};
            while (!empty(q)) {
                new_root = q[0];
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[v] != -1) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return pair(dist, new_root);
        };

        const auto& [x, u] = bfs(0);
        const auto& [dist1, v] = bfs(u);
        const auto& [dist2, y] = bfs(v);
        vector<int> result(size(adj));
        for (int w = 0; w < size(adj); ++w) {
            result[w] = dist1[w] > dist2[w] ? u : v;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// bfs
class Solution2 {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        const auto& increase = [](const auto& x) {
            return pair(x.first + 1, x.second);
        };

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&]() {
                vector<vector<pair<int, int>>> dp(size(adj), vector<pair<int, int>>(2));
                int new_root = -1;
                for (int u = 0; u < size(dp); ++u) {
                    for (auto& x : dp[u]) {
                        x.second = u;
                    }
                }
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
                            new_root = u;
                            continue;
                        }
                        --degree[u];
                        for (const auto& v : adj[u]) {
                            if (degree[v] == 0) {
                                continue;
                            }
                            auto curr = increase(dp[u][0]);
                            for (auto& x : dp[v]) {
                                if (curr > x) {
                                    swap(curr, x);
                                }
                            }
                            if (--degree[v] == 1) {
                                new_q.emplace_back(v);
                            }
                        }
                    }
                    q = move(new_q);
                }
                return pair(dp, new_root);
            };

        const auto& [dp, u] = bfs();
        const auto& bfs2 = [&](int root) {
            vector<int> result(size(adj), -1);
            vector<tuple<int, int, pair<int, int>>> q = {{root, -1, pair(0, -1)}};
            while (!empty(q)) {
                vector<tuple<int, int, pair<int, int>>> new_q;
                for (const auto& [u, p, curr] : q) {
                    result[u] = max(dp[u][0], curr).second;
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_q.emplace_back(v, u, increase(max(dp[u][dp[u][0].second == dp[v][0].second], curr)));
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        return bfs2(u);
    }
};

// Time:  O(n)
// Space: O(n)
// bfs
class Solution3 {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        const auto& increase = [](const auto& x) {
            return pair(x.first + 1, x.second);
        };

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& topological_traversal = [&]() {
            vector<int> p(size(adj), -2);
            p[0] = -1;
            vector<int> topological_order;
            topological_order.reserve(size(adj));
            topological_order.emplace_back(0);
            for (int idx = 0; idx < size(topological_order); ++idx) {
                const auto& u = topological_order[idx];
                for (const auto& v : adj[u]) {
                    if (p[v] != -2) {
                        continue;
                    }
                    p[v] = u;
                    topological_order.emplace_back(v);
                }
            }
            reverse(begin(topological_order), end(topological_order));
            vector<vector<pair<int, int>>> dp(size(adj), vector<pair<int, int>>(2));
            for (int u = 0; u < size(dp); ++u) {
                for (auto& x : dp[u]) {
                    x.second = u;
                }
            }
            for (const auto& u : topological_order) {
                for (const auto& v : adj[u]) {
                    if (v == p[u]) {
                        continue;
                    }
                    auto curr = increase(dp[v][0]);
                    for (auto& x : dp[u]) {
                        if (curr > x) {
                            swap(curr, x);
                        }
                    }
                }
            }
            return dp;
        };

        const auto& dp = topological_traversal();
        const auto& bfs = [&]() {
            vector<int> result(size(adj), -1);
            vector<tuple<int, int, pair<int, int>>> q = {{0, -1, pair(0, -1)}};
            while (!empty(q)) {
                vector<tuple<int, int, pair<int, int>>> new_q;
                for (const auto& [u, p, curr] : q) {
                    result[u] = max(dp[u][0], curr).second;
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_q.emplace_back(v, u, increase(max(dp[u][dp[u][0].second == dp[v][0].second], curr)));
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        return bfs();
    }
};

// Time:  O(n)
// Space: O(n)
// iterative dfs, tree dp
class Solution4 {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        const auto& increase = [](const auto& x) {
            return pair(x.first + 1, x.second);
        };

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs1 = [&]() {
            vector<vector<pair<int, int>>> dp(size(adj), vector<pair<int, int>>(2));
            for (int u = 0; u < size(dp); ++u) {
                for (auto& x : dp[u]) {
                    x.second = u;
                }
            }
            vector<tuple<int, int, int, int>> stk = {{1, 0, -1, -1}};
            while (!empty(stk)) {
                const auto [step, u, p, i] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p, 0);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p, i + 1);
                    const int v = adj[u][i];
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(3, v, u, -1);
                    stk.emplace_back(1, v, u, -1);
                } else if (step == 3) {
                    auto curr = increase(dp[u][0]);
                    for (auto& x : dp[p]) {
                        if (curr > x) {
                            swap(curr, x);
                        }
                    }
                }
            }
            return dp;
        };

        const auto& dp = iter_dfs1();
        const auto& iter_dfs2 = [&]() {
            vector<int> result(size(adj), -1);
            vector<tuple<int, int, pair<int, int>>> stk = {{0, -1, pair(0, -1)}};
            while (!empty(stk)) {
                const auto [u, p, curr] = stk.back(); stk.pop_back();
                result[u] = max(dp[u][0], curr).second;
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u, increase(max(dp[u][dp[u][0].second == dp[v][0].second], curr)));
                }
            }            
            return result;
        };

        return iter_dfs2();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution5 {
public:
    vector<int> lastMarkedNodes(vector<vector<int>>& edges) {
        const auto& increase = [](const auto& x) {
            return pair(x.first + 1, x.second);
        };

        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<vector<pair<int, int>>> dp(size(adj), vector<pair<int, int>>(2));
        for (int u = 0; u < size(dp); ++u) {
            for (auto& x : dp[u]) {
                x.second = u;
            }
        }
        const function<void (int, int)> dfs1 = [&](int u, int p) {
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs1(v, u);
                auto curr = increase(dp[v][0]);
                for (auto& x : dp[u]) {
                    if (curr > x) {
                        swap(curr, x);
                    }
                }
            }
        };

        dfs1(0, -1);
        vector<int> result(size(adj), -1);
        const function<void (int, int, pair<int, int>)> dfs2 = [&](int u, int p, const auto& curr) {
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs2(v, u, increase(max(dp[u][dp[u][0].second == dp[v][0].second], curr)));
            }
            result[u] = max(dp[u][0], curr).second;
        };

        dfs2(0, -1, pair(0, -1));
        return result;
    }
};
