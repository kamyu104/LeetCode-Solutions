// Time:  O(n + k)
// Space: O(k)

// dp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<int> dp(k);
        for (const auto& x : nums) {
            dp[x % k] = max(dp[x % k], dp[(k - x % k) % k] + 1);
        }
        return ranges::max(dp);
    }
};
