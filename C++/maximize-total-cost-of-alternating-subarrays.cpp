// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<int64_t> dp = { nums[0], numeric_limits<int64_t>::min() };
        for (int i = 1; i < size(nums); ++i) {
            dp = {max(dp[0], dp[1]) + nums[i], dp[0] - nums[i]};
        }
        return max(dp[0], dp[1]);
    }
};
