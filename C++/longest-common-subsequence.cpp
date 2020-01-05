// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
                if (text1.length() < text2.length()) {
            return longestCommonSubsequence(text2, text1);
        }
        vector<vector<int>> dp(2, vector<int>(text2.length() + 1));
        for (int i = 1; i <= text1.length(); ++i) {
            for (int j = 1; j <= text2.length(); ++j) {
                dp[i % 2][j] = (text1[i - 1] == text2[j - 1])
                               ? dp[(i - 1) % 2][j - 1] + 1
                               : max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                               
            }
        }
        return dp[text1.length() % 2][text2.length()];
    }
};
