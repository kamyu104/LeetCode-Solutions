// Time:  O(n * k)
// Space: O(k)

// dp, combinatorics
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(k + 1);
        dp[0] = 1;
        for (const auto& x : nums) {
            for (int i = k; i >= 0; --i) {
                dp[i] = (dp[i] + (dp[i] + (i - x >= 0 ? dp[i - x] : 0)) % MOD) % MOD;
            }
        }
        return dp[k];
    }
};
