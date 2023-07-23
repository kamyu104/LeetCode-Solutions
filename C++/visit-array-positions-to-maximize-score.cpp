// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        static const int64_t MIN = numeric_limits<int64_t>::min();
        vector<int64_t> dp(2, MIN);
        dp[nums[0] % 2] = nums[0];
        for (int i = 1; i < size(nums); ++i) {
            dp[nums[i] % 2] = max(dp[nums[i] % 2], dp[(nums[i] + 1) % 2] != MIN ? dp[(nums[i] + 1) % 2] - x : MIN) + nums[i];
        }
        return max(dp[0], dp[1]);
    }
};
