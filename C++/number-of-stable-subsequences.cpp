// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<vector<int64_t>> dp(2, vector<int64_t>(2));  // dp[p][i]: count of subsequences that end with exactly (i+1) consecutive numbers of parity p
        for (const auto& x : nums) {
            const auto& p = x % 2;
            dp[p][1] = (dp[p][1] + dp[p][0]) % MOD;
            dp[p][0] = (dp[p][0] + 1 + dp[1 ^ p][0] + dp[1 ^ p][1]) % MOD;
        }
        return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % MOD;
    }
};
