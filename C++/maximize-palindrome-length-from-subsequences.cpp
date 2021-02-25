// Time:  O((m + n)^2)
// Space: O((m + n)^2)

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        vector<vector<int>> dp(size(s), vector<int>(size(s)));
        int result = 0;
        for (int j = 0; j < size(s); ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 == j) ? 2 : dp[i + 1][j - 1] + 2;
                    if (i < size(word1) && size(word1) <= j) {
                        result = max(result, dp[i][j]);
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return result;
    }
};

// Time:  O((m + n)^2)
// Space: O((m + n)^2)
class Solution2 {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        vector<vector<int>> dp(size(s), vector<int>(size(s)));
        for (int j = 0; j < size(s); ++j) {
            dp[j][j] = 1;
            for (int i = j - 1; i >= 0; --i) {
                if (s[i] == s[j]) {
                    dp[i][j] = (i + 1 == j) ? 2 : dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(word1); ++i) {
            for (int j = size(word1); j < size(s); ++j) {
                if (s[i] == s[j]) {
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};
