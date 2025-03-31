// Time:  O(n^2)
// Space: O(n)

// prefix sum, dp
class Solution {
public:
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        vector<int64_t> prefix1(size(nums) + 1);
        vector<int64_t> prefix2(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix1[i + 1] = prefix1[i] + nums[i];
            prefix2[i + 1] = prefix2[i] + cost[i];
        }
        vector<int64_t> dp(size(nums) + 1, numeric_limits<int64_t>::max());
        dp.back() = 0;
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int j = i; j < size(nums); ++j) {
                dp[i] = min(dp[i], prefix1[j + 1] * (prefix2[j + 1] - prefix2[i]) + dp[j + 1] + (k * (prefix2.back() - prefix2[i])));
            }
        }
        return dp[0];
    }
};
