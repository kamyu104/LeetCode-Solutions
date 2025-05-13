// Time:  O(k * e * t)
// Space: O(n * t)

// dp
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
        }
        vector<unordered_set<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].emplace(0);
        }
        for (int _ = 0; _ < k; ++_) {
            vector<unordered_set<int>> new_dp(n);
            for (int i = 0; i < n; ++i) {
                for (const auto& c : dp[i]) {
                    for (const auto& [j, w] : adj[i]) {
                        if (c + w < t) {
                            new_dp[j].emplace(c + w);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = -1;
        for (const auto& x : dp) {
            if (!empty(x)) {
                result = max(result, ranges::max(x));
            }
        }
        return result;
    }
};
