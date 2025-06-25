// Time:  O(n)
// Space: O(1)

// dp, bitmasks
class Solution {
public:
    vector<int> onceTwice(vector<int>& nums) {
        vector<int> dp(3), new_dp(3);
        dp[0] = ~0;
        for (const auto& x : nums) {
            for (int i = 0; i < 3; ++i) {
                new_dp[i] = (x & dp[i - 1 >= 0 ? i - 1 : 2]) | (~x & dp[i]);
            }
            swap(dp, new_dp);
        }
        vector<int> dp2(3), new_dp2(3);
        dp2[0] = ~0;
        for (const auto& x : nums) {
            if ((~x & dp[1]) || (x & dp[2])) {
                continue;
            }
            for (int i = 0; i < 3; ++i) {
                new_dp2[i] = (x & dp2[i - 1 >= 0 ? i - 1 : 2]) | (~x & dp2[i]);
            }
            swap(dp2, new_dp2);
        }
        return {dp2[1], (dp2[1] ^ dp[1]) | dp[2]};
    }
};
