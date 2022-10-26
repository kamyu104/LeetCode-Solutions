// Time:  O(nlogr), r = max(nums)
// Space: O(logr)

// dp
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> dp;
        for (const auto& x: nums) {
            unordered_map<int, int> new_dp;
            if (x % k == 0) {
                ++dp[x];
                for (const auto& [g, cnt] : dp) {
                    new_dp[gcd(g, x)] += cnt;
                }
            }
            dp = new_dp;
            result += dp[k];
        }
        return result;
    }
};
