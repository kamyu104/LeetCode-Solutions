// Time:  O(n * m)
// Space: O(n * m)

// dp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        static const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2)));
        for (int i = 0; i <= zero; ++i) {
            dp[i][0][0] = i <= limit ? 1 : 0;
        }
        for (int j = 0; j <= one; ++j) {
            dp[0][j][1] = j <= limit ? 1 : 0;
        }
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if (i - limit - 1 >= 0) {
                    dp[i][j][0] = ((dp[i][j][0] - dp[i - limit - 1][j][1]) % MOD + MOD) % MOD;
                }
                if (j - limit - 1 >= 0) {
                    dp[i][j][1] = ((dp[i][j][1] - dp[i][j - limit - 1][0]) % MOD + MOD) % MOD;
                }
            }
        }
        return (dp.back().back()[0] + dp.back().back()[1]) % MOD;
    }
};

// Time:  O(n * m * l)
// Space: O(n * m)
// dp
class Solution2 {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        static const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2)));
        dp[0][0][0] = dp[0][0][1] = 1;
        for (int i = 0; i <= zero; ++i) {
            for (int j = 0; j <= one; ++j) {
                for (int k = 1; k <= limit; ++k) {
                    if (i - k >= 0) {
                        dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                    }
                    if (j - k >= 0) {
                        dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                    }
                }
            }
        }
        return (dp.back().back()[0] + dp.back().back()[1]) % MOD;
    }
};
