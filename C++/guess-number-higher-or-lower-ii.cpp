// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));  // dp[i][j]: min pay in [i+1, j+1)
        for (int j = 0; j <= n; ++j) {
            for (int i = j - 2; i >= 0; --i) {
                dp[i][j] = numeric_limits<int>::max();
                for (int k = i; k < j; ++k) {
                    if (max(dp[i][k], dp[k + 1][j]) < dp[i][j] - (k + 1)) {
                        dp[i][j] = (k + 1) + max(dp[i][k], dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n];
    }
};

// Time:  O(n^3)
// Space: O(n^2)
class Solution2 {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));  // dp[i][j]: min pay in [i+1, j+1)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j <= n; ++j) {
                dp[i][j] = numeric_limits<int>::max();
                for (int k = i; k < j; ++k) {
                    if (max(dp[i][k], dp[k + 1][j]) < dp[i][j] - (k + 1)) {
                        dp[i][j] = (k + 1) + max(dp[i][k], dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n];
    }
};
