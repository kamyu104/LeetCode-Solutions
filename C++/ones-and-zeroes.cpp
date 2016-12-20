// Time:  O(s * m * n), s is the size of the array.
// Space: O(m * n)

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (const auto &str : strs) {
            int zero_count = 0, one_count = 0;
            for (const auto& c : str) {
                if (c == '0') {
                    ++zero_count;
                } else if (c == '1') {
                    ++one_count;
                }
            }

            for (int i = m; i - zero_count >= 0; --i) {
            	for (int j = n; j - one_count >= 0; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1);
            	}
            }
        }
        return dp[m][n];
    }
};
