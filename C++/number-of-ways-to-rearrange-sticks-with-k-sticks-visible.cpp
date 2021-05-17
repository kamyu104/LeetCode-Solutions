// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                // choose the tallest as the last one which would be visible:    dp[i-1][j-1]
                // choose the non-tallest as the last one which would be hidden: (i-1)*dp[i-1][j]
                dp[i % 2][j] = (dp[(i - 1) % 2][j - 1] + int64_t(i - 1) * dp[(i - 1) % 2][j]) % MOD;
            }
        }
        return dp[n % 2][k];
    }
};
