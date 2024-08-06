// Time:  O(n)
// Space: O(n)

// tree dp, bfs
class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<vector<pair<int, int>>> dp(size(edges) + 1, vector<pair<int, int>>(2, pair(0, -1)));
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
            for (const auto& u : topological_order) {
                for (const auto& v : adj[u]) {
                    if (v == p[u]) {
                        continue;
                    }
                    pair<int, int> curr = pair((v % 2 ? 1 : 2) + dp[v][0].first, v);
                    for (int i = 0; i < size(dp[u]); ++i) {
                        if (curr > dp[u][i]) {
                            swap(curr, dp[u][i]);
                        }
                    }
                }
            }
        };

        vector<int> result(size(edges) + 1);
        const auto& bfs = [&]() {
            vector<tuple<int, int, int>> q = {{0, -1, 0}};
            while (!empty(q)) {
                vector<tuple<int, int, int>> new_q;
                for (const auto& [u, p, curr] : q) {
                    result[u] = max(dp[u][0].first, curr);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_q.emplace_back(v, u, (u % 2 ? 1 : 2) + max(dp[u][dp[u][0].second == v].first, curr));
                    }
                }
                q = move(new_q);
            }
        };
    
        topological_traversal();
        bfs();
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// tree dp, dfs
class Solution2 {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<vector<pair<int, int>>> dp(size(edges) + 1, vector<pair<int, int>>(2, pair(0, -1)));
        const function<void (int, int)> dfs1 = [&](int u, int p) {
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs1(v, u);
                pair<int, int> curr = pair((v % 2 ? 1 : 2) + dp[v][0].first, v);
                for (int i = 0; i < size(dp[u]); ++i) {
                    if (curr > dp[u][i]) {
                        swap(curr, dp[u][i]);
                    }
              }
            }
        };

        vector<int> result(size(edges) + 1);
        const function<void (int, int, int)> dfs2 = [&](int u, int p, int curr) {
            result[u] = max(dp[u][0].first, curr);
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs2(v, u, (u % 2 ? 1 : 2) + max(dp[u][dp[u][0].second == v].first, curr));
            }
        };
    
        dfs1(0, -1);
        dfs2(0, -1, 0);
        return result;
    }
};
