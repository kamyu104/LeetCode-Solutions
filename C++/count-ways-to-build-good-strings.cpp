// Time:  O(n)
// Space: O(n)

// dp
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
            if (i >= low) {
                result = (result + dp[i]) % MOD;
            }
        }
        return result;
    }
};
