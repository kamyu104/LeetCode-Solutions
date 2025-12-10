// Time:  O(n)
// Space: O(n)

// bfs, tree dp
class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int> parent(n, -1);
        vector<int> q = {0};
        for (int i = 0; i < n; ++i) {
            const auto u = q[i];
            for (const auto& v : adj[u]) {
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                q.emplace_back(v);
            }
        }
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = good[i] ? 1 : -1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (parent[q[i]] == -1) {
                continue;
            }
            dp[parent[q[i]]] += max(dp[q[i]], 0);
        }
        for (int i = 0; i < n; ++i) {
            if (parent[q[i]] == -1) {
                continue;
            }
            dp[q[i]] += max(dp[parent[q[i]]] - max(dp[q[i]], 0), 0);
        }
        return dp;
    }
};
