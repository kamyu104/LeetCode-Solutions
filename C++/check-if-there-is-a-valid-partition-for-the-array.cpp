// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(4);
        dp[0] = 1;
        for (int i = 0; i < size(nums); ++i) {
            dp[(i + 1) % 4] = 0;
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) {
                dp[(i + 1) % 4] |= dp[((i + 1) - 2) % 4];
            }
            if (i - 2 >= 0 &&
                ((nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) ||
                 (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))) {
                dp[(i + 1) % 4] |= dp[((i + 1) - 3) % 4];
            }
        }
        return dp[size(nums) % 4];
    }
};
