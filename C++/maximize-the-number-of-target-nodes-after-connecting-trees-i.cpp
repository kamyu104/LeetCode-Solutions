// Time:  O(nlogn + mlogm)
// Space: O(n + m)

// dfs, centroid decomposition, prefix sum
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const auto& centroid_decomposition = [](const auto& adj, int k) {
            vector<int> result(size(adj));
            vector<int> sizes(size(adj));
            vector<bool> lookup(size(adj));
            vector<vector<int>> prefix(size(adj));
            vector<int> cnt;
            vector<int> total, curr;

            const function<void (int)> dfs = [&](int u) {
                // https://usaco.guide/plat/centroid
                const function<int (int, int)> find_subtree_size = [&](int u, int p) {
                    sizes[u] = 1;
                    for (const auto& v : adj[u]) {
                        if (v == p || lookup[v]) {
                            continue;
                        }
                        sizes[u] += find_subtree_size(v, u);
                    }
                    return sizes[u];
                };

                find_subtree_size(u, -1);
                const int n = sizes[u];
                const function<int (int, int)> find_centroid = [&](int u, int p) {
                    for (const auto& v : adj[u]) {
                        if (v == p || lookup[v]) {
                            continue;
                        }
                        if (sizes[v] * 2 > n) {
                            return find_centroid(v, u);
                        }
                    }
                    return u;
                };

                const function<void (int, int, int)> count = [&](int u, int p, int d) {
                    if (d > k) {
                        return;
                    }
                    if (d - 1 == size(cnt)) {
                        cnt.emplace_back(0);
                    }
                    ++cnt[d - 1];
                    for (const auto& v : adj[u]) {
                        if (v == p || lookup[v]) {
                            continue;
                        }
                        count(v, u,  d + 1);
                    }
                };

                const function<void (int, int, int)> update = [&](int u, int p, int d) {
                    if (d > k) {
                        return;
                    }
                    result[u] += total[min(k - d, static_cast<int>(size(total)) - 1)] - curr[min(k - d, static_cast<int>(size(curr)) - 1)];
                    for (const auto& v : adj[u]) {
                        if (v == p || lookup[v]) {
                            continue;
                        }
                        update(v, u,  d + 1);
                    }
                };

                u = find_centroid(u, -1);
                lookup[u] = true;
                int max_d = 0;
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    cnt.clear();
                    count(v, u, 0 + 1);
                    prefix[v].emplace_back(0);
                    for (int d = 0; d < size(cnt); ++d) {
                        prefix[v].emplace_back(prefix[v].back() + cnt[d]);
                    }
                    max_d = max(max_d, static_cast<int>(size(cnt)));
                }
                total.assign(max_d + 1, 1);
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    for (int d = 0; d < size(total); ++d) {
                        total[d] += prefix[v][min(d, static_cast<int>(size(prefix[v])) - 1)];
                    }
                }
                result[u] += total[min(k, static_cast<int>(size(total)) - 1)];
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    curr = move(prefix[v]);
                    update(v, u, 0 + 1);
                }
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    dfs(v);
                }
            };

            if (k >= 0) {
                dfs(0);
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
        int mx = ranges::max(centroid_decomposition(adj2, k - 1));
        const auto& adj1 = find_adj(edges1);
        vector<int> result(size(adj1));
        const auto& ret = centroid_decomposition(adj1, k);
        for (int u = 0; u < size(adj1); ++u) {
            result[u] = mx + ret[u];
        }
        return result;
    }
};

// Time:  O((n + m) * k)
// Space: O((n + m) * k)
// dfs, tree dp
class Solution2 {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        const auto& tree_dp = [](const auto& adj, int k) {
            vector<int> result(size(adj));
            k = min(k, static_cast<int>(size(adj)) - 1);
            if (k == -1) {
                return result;
            }
            vector<vector<int>> dp(size(adj), vector<int>(k + 1));
            const function<void (int, int)> dfs1 = [&](int u, int p) {
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    dfs1(v, u);
                }
                ++dp[u][0];
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    for (int d = 0; d < k; ++d) {
                        dp[u][d + 1] += dp[v][d];
                    }
                }
            };

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
class Solution3 {
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
