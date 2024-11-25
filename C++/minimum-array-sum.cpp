// Time:  O(n * op1 * op2)
// Space: O(op1 * op2)

// dp
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, accumulate(cbegin(nums), cend(nums), 0)));
        for (int x : nums) {
            for (int i = op1; i >= 0; --i) {
                for (int j = op2; j >= 0; --j) {
                    if (i - 1 >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] - x + (x + 1) / 2);
                    }
                    if (j - 1 >= 0) {
                        if (x - k >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i][j - 1] - x + (x - k));
                        }
                    }
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if (x - k >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - x + (((x - k) + 1) / 2));
                        }
                        if ((x + 1) / 2 - k >= 0) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - x + ((x + 1) / 2 - k));
                        }
                    }
                }
            }
        }
        return dp[op1][op2];
    }
};
