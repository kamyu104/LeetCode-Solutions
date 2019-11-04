// Time:  O(d * f * t)
// Space: O(t)

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        static const int MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= d; ++i) {
            dp[i % 2] = vector<int>(target + 1);
            for (int k = 1; k <= f; ++k) {
                for (int j = k; j <= target; ++j) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j - k]) % MOD;
                }
            }
        }
        return dp[d % 2][target] % MOD;
    }
};
