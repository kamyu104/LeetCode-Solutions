// Time:  O(k * n^2)
// Space: O(n)

// dp
class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> dp(n);
        for (int i = 0; i < k; ++i) {
            vector<int> new_dp(n);
            for (int u = 0; u < n; ++u) {
                new_dp[u] = dp[u] + stayScore[i][u];
            }
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    new_dp[u] = max(new_dp[u], dp[v] + travelScore[v][u]);
                }
            }
            dp = move(new_dp);
        }
        return ranges::max(dp);
    }
};
