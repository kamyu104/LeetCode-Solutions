// Time:  O(n)
// Space: O(n)

// bfs, greedy
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& bfs = [&]() {
            vector<int> cnt(n);
            for (int u = 0; u < n; ++u) {
                cnt[u] = size(adj[u]);
            }
            int result = 0;
            vector<int> dp(size(values));
            transform(cbegin(values), cend(values), begin(dp), [&](const auto& x) {
                return x % k;
            });
            vector<int> q;
            for (int u = 0; u < n; ++u) {
                if (cnt[u] == 1) {
                    q.emplace_back(u);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    if (!dp[u]) {
                        ++result;
                    }
                    for (const auto& v : adj[u]) {
                        dp[v] = (dp[v] + dp[u]) % k;
                        if (--cnt[v] == 1) {
                            new_q.emplace_back(v);
                        }
                    }
                }
                q = move(new_q);
            }
            return max(result, 1);
        };

        return bfs();
    }
};
