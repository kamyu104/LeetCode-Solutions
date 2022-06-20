// Time:  O(m * n * (m + n))
// Space: O(m * n)

// dp
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int64_t>> dp(m + 1, vector<int64_t>(n + 1));
        for (const auto& p : prices) {
            dp[p[0]][p[1]] = p[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= i / 2; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k <= j / 2; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
        return dp[m][n];
    }
};
