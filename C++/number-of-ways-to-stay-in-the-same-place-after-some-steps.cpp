// Time:  O(n^2), n is the number of steps
// Space: O(n)

class Solution {
public:
    int numWays(int steps, int arrLen) {
        static const int MOD = 1000000007;
        const int l = min(1 + steps / 2, arrLen);
        vector<int> dp(l + 2);
        dp[1] = 1;
        while (steps-- > 0) {
            vector<int> new_dp(l + 2);
            for (int i = 1; i <= l; ++i) {
                new_dp[i] = (uint64_t(dp[i]) + dp[i - 1] + dp[i + 1]) % MOD;
            }
            dp = move(new_dp);
        }
        return dp[1];
    }
};
