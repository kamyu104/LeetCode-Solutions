// Time:  O(m^2)
// Space: O(m)

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<int> dp(size(multipliers) + 1);
        for (int i = size(multipliers) - 1, l = size(nums) - size(multipliers); i >= 0 ; --i, ++l) {
            vector<int> new_dp(size(dp) - 1);
            for (int j = 0; j < size(new_dp); ++j) {
                new_dp[j] = max(multipliers[i] * nums[j]+ dp[j + 1],
                                multipliers[i] * nums[j + l] + dp[j]);
            }
            dp = move(new_dp);
        }
        return dp[0];
    }
};
