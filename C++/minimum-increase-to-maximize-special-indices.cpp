// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int64_t dp = 0;
        if (size(nums) % 2) {
            for (int i = 1; i + 1 < size(nums); i += 2) {
                dp += max((max(nums[i - 1], nums[i + 1]) + 1) - nums[i], 0);
            }
            return dp;
        }
        int64_t dp2 = 0;
        for (int i = 1; i + 1 < size(nums); i += 2) {
            dp += max((max(nums[i - 1], nums[i + 1]) + 1) - nums[i], 0);
            dp2 += max((max(nums[i], nums[i + 2]) + 1) - nums[i + 1], 0);
            dp2 = min(dp2, dp);
        }
        return dp2;
    }
};
