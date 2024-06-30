// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> dp(k);
            for (const auto& x : nums) {
                dp[x % k] = dp[((i - x) % k + k) % k] + 1;
            }
            result = max(result, ranges::max(dp));
        }
        return result;
    }
};
