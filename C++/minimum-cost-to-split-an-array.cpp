// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        vector<int> dp(size(nums) + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i + 1 < size(dp); ++i) {
            vector<int> cnt(size(nums));
            int d = 0;
            for (int j = i + 1; j < size(dp); ++j) {
                if (++cnt[nums[j - 1]] == 1) {
                    ++d;
                } else if (cnt[nums[j - 1]] == 2) {
                    --d;
                }
                dp[j] = min(dp[j], dp[i] + k + ((j - i) - d));
            }
        }
        return dp.back();
    }
};
