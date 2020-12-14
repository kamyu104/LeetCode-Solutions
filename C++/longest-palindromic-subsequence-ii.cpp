// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    static const int MAX_LEN = 250;
    int dp[2][MAX_LEN][26];  // to speed up dp
    int longestPalindromeSubseq(string s) {
        // vector<vector<vector<int>>> dp(2, vector<vector<int>>(size(s), vector<int>(26)));
        for (int i = size(s) - 1; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                if (i == j - 1) {
                    if (s[j] == s[i]) {
                        dp[i % 2][j][s[j] - 'a'] = 2;
                    }
                } else {
                    for (int k = 0; k < 26; ++k) {
                        if(s[j] == s[i] && s[j] - 'a' != k) {
                            dp[i % 2][j][s[j] - 'a'] = max(dp[i % 2][j][s[j] - 'a'],
                                                           dp[(i + 1) % 2][j - 1][k] + 2);
                        }
                        dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[i % 2][j - 1][k]);
                        dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j][k]);
                        dp[i % 2][j][k] = max(dp[i % 2][j][k], dp[(i + 1) % 2][j - 1][k]);
                    }
                }
            }
        }
        return *max_element(cbegin(dp[0][size(s) - 1]), cend(dp[0][size(s) - 1]));        
    }
};
