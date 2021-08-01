// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int64_t> dp(3);
        for (const auto& x : nums) {
            dp[x] = ((dp[x] + dp[x]) % MOD + (x - 1 >= 0  ? dp[x - 1] : 1)) % MOD;
        }
        return dp.back();
    }
};
