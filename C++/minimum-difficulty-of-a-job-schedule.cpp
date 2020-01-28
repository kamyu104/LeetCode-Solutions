// Time:  O(d * n^2)
// Space: O(d * n)

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) {
            return -1;
        }

        vector<vector<int>> dp(d,
                               vector<int>(jobDifficulty.size(),
                                           numeric_limits<int>::max()));
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < jobDifficulty.size(); ++i) {
            dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < jobDifficulty.size(); ++j) {
                int curr_max = jobDifficulty[j];
                for (int k = j; k >= i; --k) {
                    curr_max = max(curr_max, jobDifficulty[k]);
                    if (dp[i - 1][k - 1] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + curr_max);
                    }
                }
            }
        }
        return dp[d - 1][jobDifficulty.size() - 1];
    }
};
