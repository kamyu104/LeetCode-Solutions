// Time:  O(m * n)
// Space: O(n)

// DP with rolling window.
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(2, vector<int>(s2.length() + 1));
        for (int j = 0; j < s2.length(); ++j) {
            dp[0][j + 1] = dp[0][j] + s2[j];
        }

        for (int i = 0; i < s1.length(); ++i) {
            dp[(i + 1) % 2][0] = dp[i % 2][0] + s1[i];
            for (int j = 0; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j];
                } else {
                    dp[(i + 1) % 2][j + 1] = min(dp[i % 2][j + 1] + s1[i],
                                                 dp[(i + 1) % 2][j] + s2[j]);
                }
            }
        }

        return dp[s1.length() % 2][s2.length()];
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
        for (int i = 0; i < s1.length(); ++i) {
            dp[i + 1][0] = dp[i][0] + s1[i];
        }
        for (int j = 0; j < s2.length(); ++j) {
            dp[0][j + 1] = dp[0][j] + s2[j];
        }

        for (int i = 0; i < s1.length(); ++i) {
            for (int j = 0; j < s2.length(); ++j) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + s1[i],
                                           dp[i + 1][j] + s2[j]);
                }
            }
        }

        return dp[s1.length()][s2.length()];
    }
};
