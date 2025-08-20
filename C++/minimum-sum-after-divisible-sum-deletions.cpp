// Time:  O(n + k)
// Space: O(k)

// dp, prefix sum
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<int64_t> dp(k, numeric_limits<int64_t>::max());
        dp[0] = 0;
        int64_t result = 0;
        for (const auto& x : nums) {
            result += x;
            dp[result % k] = result = min(result, dp[result % k]);
        }
        return result;
    }
};
