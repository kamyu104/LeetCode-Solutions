// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        const auto m = word1.length();
        const auto n = word2.length();

        vector<vector<int>> dp(2, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[(i + 1) % 2][j + 1] = max(max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]),
                                             dp[i % 2][j] + (word1[i] == word2[j]));
            }
        }
        return m + n - 2 * dp[m % 2][n];
    }
};
