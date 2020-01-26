// Time:  O(n^2 * d)
// Space: O(n^2)

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) {
            return -1;
        }

        vector<vector<int>> max_in_range(jobDifficulty.size(),
                                         vector<int>(jobDifficulty.size()));
        for (int i = 0; i < jobDifficulty.size(); ++i) {
            max_in_range[i][i] = jobDifficulty[i];
            for (int j = i + 1; j < jobDifficulty.size(); ++j) {
                max_in_range[i][j] = max(max_in_range[i][j - 1], jobDifficulty[j]);
            }
        }
        
        vector<vector<int>> dp(jobDifficulty.size(),
                               vector<int>(d, numeric_limits<int>::max()));
        for (int i = 0; i < jobDifficulty.size(); ++i) {
            dp[i][0] = max_in_range[0][i];
            for (int j = 1; j < d; ++j) {
                for (int k = i - 1; k >= 0; --k) {
                    if (dp[k][j - 1] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + max_in_range[k + 1][i]);
                    }
                }
            }
        }
        return dp[jobDifficulty.size() - 1][d - 1];
    }
};
