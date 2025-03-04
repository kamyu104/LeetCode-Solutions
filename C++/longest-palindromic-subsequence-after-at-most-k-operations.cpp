// Time:  O(n^2 * k)
// Space: O(n^2 * k)

// dp
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        vector<vector<vector<int>>> dp(size(s), vector<vector<int>>(size(s), vector<int>(k + 1)));
        for (int i = 0; i < size(s); ++i) {
            for (int x = 0; x <= k; ++x) {
                dp[i][i][x] = 1;
            }
        }
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                for (int x = 0; x <= k; ++x) {
                    if (s[i] == s[j]) {
                        dp[i][j][x] = dp[i + 1][j - 1][x] + 2;
                    } else {
                        dp[i][j][x] = max(dp[i + 1][j][x], dp[i][j - 1][x]);
                        const int diff = abs(s[i] - s[j]);
                        const int c = min(diff, 26 - diff);
                        if (x >= c) {
                            dp[i][j][x] = max(dp[i][j][x], dp[i + 1][j - 1][x - c] + 2);
                        }
                    }
                }
            }
        }
        return dp[0][size(s) - 1][k];
    }
};
