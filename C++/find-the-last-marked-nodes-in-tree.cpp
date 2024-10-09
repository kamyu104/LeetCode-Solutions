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
// iterative dfs, tree dp
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
                    auto tmp = pair(dp[u][0].first + 1, dp[u][0].second);
                    for (auto& x : dp[p]) {
                        if (tmp > x) {
                            swap(tmp, x);
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
                auto tmp = pair(dp[v][0].first + 1, dp[v][0].second);
                for (auto& x : dp[u]) {
                    if (tmp > x) {
                        swap(tmp, x);
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
