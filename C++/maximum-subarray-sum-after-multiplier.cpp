// Time:  O(n)
// Space: O(1)

// dp, kadane's algorithm
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();
        enum {INIT, MULT, DIV, DONE};

        int64_t result = NEG_INF;
        vector<int64_t> dp(4, NEG_INF);
        for (const int64_t x : nums) {
            dp = {
                max(dp[INIT], static_cast<int64_t>(0)) + x,
                max({dp[MULT], dp[INIT], static_cast<int64_t>(0)}) + x * k,
                max({dp[DIV], dp[INIT], static_cast<int64_t>(0)}) + x / k,
                max({dp[DONE], dp[MULT], dp[DIV], static_cast<int64_t>(0)}) + x,
            };
            result = max(result, ranges::max(dp));
        }
        return result;
    }
};
