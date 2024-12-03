// Time:  O((n + m) * k)
// Space: O((n + m) * k)

// dfs, tree dp
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const auto& tree_dp = [](const auto& adj, int k) {
            k = min(k, static_cast<int>(size(adj)) - 1);
            vector<vector<int>> dp(size(adj), vector<int>(k + 1));
            const function<void (int, int)> dfs1 = [&](int u, int p) {
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    dfs1(v, u);
                }
                if (0 < size(dp[u])) {
                    ++dp[u][0];
                }
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    for (int d = 0; d < k; ++d) {
                        dp[u][d + 1] += dp[v][d];
                    }
                }
            };

            vector<int> result(size(adj));
            const function<void(int, int, const vector<int>&)> dfs2 = [&](int u, int p, const auto& curr) {
                const auto& update = [&](int v, int u, const auto& curr) {
                    vector<int> new_curr(size(curr));
                    for (int d = 0; d + 1 < size(new_curr); ++d) {
                        new_curr[d + 1] = curr[d] + (dp[u][d] - (d - 1 >= 0 ? dp[v][d - 1] : 0));
                    }
                    return new_curr;
                };

                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    dfs2(v, u, update(v, u, curr));
                }
                for (int d = 0; d < size(curr); ++d) {
                    result[u] += dp[u][d] + curr[d];
                }
            };

            dfs1(0, -1);
            dfs2(0, -1, vector<int>(k + 1));
            return result;
        };

        const auto& find_adj = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            return adj;
        };

        const auto& adj2 = find_adj(edges2);
        int mx = ranges::max(tree_dp(adj2, k - 1));
        const auto& adj1 = find_adj(edges1);
        vector<int> result(size(adj1));
        const auto& ret = tree_dp(adj1, k);
        for (int u = 0; u < size(adj1); ++u) {
            result[u] = mx + ret[u];
        }
        return result;
    }
};

// Time:  O(n^2 + m^2)
// Space: O(n + m)
// brute force, bfs
class Solution2 {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const auto& bfs = [](int u, const auto& adj, int k) {
            int result = 0;
            vector<pair<int, int>> q = {{u, -1}};
            while (!empty(q)) {
                if (k == -1) {
                    break;
                }
                --k;
                vector<pair<int, int>> new_q;
                result += size(q);
                for (const auto& [u, p] : q) {
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_q.emplace_back(v, u);
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        const auto& find_adj = [](const auto& edges) {
            vector<vector<int>> adj(size(edges) + 1);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            return adj;
        };

        const auto& adj2 = find_adj(edges2);
        int mx = 0;
        for (int u = 0; u < size(adj2); ++u) {
            mx = max(mx, bfs(u, adj2, k - 1));
        }
        const auto& adj1 = find_adj(edges1);
        vector<int> result(size(adj1));
        for (int u = 0; u < size(adj1); ++u) {
            result[u] = mx + bfs(u, adj1, k);
        }
        return result;
    }
};
