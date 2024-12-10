// Time:  O(n)
// Space: O(k)

// prefix sum, dp
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        vector<int64_t> dp(k, INF);
        dp.back() = 0;
        int64_t result = numeric_limits<int64_t>::min();
        for (int64_t i = 0, curr = 0; i < size(nums); ++i) {
            curr += nums[i];
            if (dp[i % k] != INF) {
                result = max(result, curr - dp[i % k]);
            }
            dp[i % k] = min(dp[i % k] , curr);
        }
        return result;
    }
};
