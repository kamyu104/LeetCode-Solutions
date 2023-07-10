// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(size(nums), -1);
        dp[0] = 0;
        for (int i = 1; i < size(nums); ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(nums[i] - nums[j]) <= target) {
                    if (dp[j] != -1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp.back();
    }
};
