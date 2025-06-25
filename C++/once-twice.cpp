// Time:  O(n)
// Space: O(1)

// dp, bitmasks
class Solution {
public:
    vector<int> onceTwice(vector<int>& nums) {
        vector<int> dp(3);
        dp[0] = ~0;
        for (const auto& x : nums) {
            vector<int> new_dp(dp);
            for (int i = 0; i < 3; ++i) {
                new_dp[i] = (x & dp[i - 1 >= 0 ? i - 1 : 2]) | (~x & dp[i]);
            }
            dp = move(new_dp);
        }
        vector<int> dp2(3);
        dp2[0] = ~0;
        for (const auto& x : nums) {
            if ((~x & dp[1]) || (x & dp[2])) {
                continue;
            }
            vector<int> new_dp2(dp2);
            for (int i = 0; i < 3; ++i) {
                new_dp2[i] = (x & dp2[i - 1 >= 0 ? i - 1 : 2]) | (~x & dp2[i]);
            }
            dp2 = move(new_dp2);
        }
        return {dp2[1], (dp2[1] ^ dp[1]) | dp[2]};
    }
};
