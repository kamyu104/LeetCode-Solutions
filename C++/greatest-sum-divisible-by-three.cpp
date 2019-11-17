// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        for (const auto& num : nums) {
            vector<int> new_dp(dp);
            for (auto& x : dp) {
                x += num;
            }
            for (const auto& i : dp) {
                new_dp[i % 3] = max(new_dp[i % 3], i);
            }
            dp = move(new_dp);
        }
        return dp[0];
    }
};
