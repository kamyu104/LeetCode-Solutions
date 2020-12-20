// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int waysToDistribute(int n, int k) {
        static int MOD = 1e9 + 7;
        vector<int64_t> dp(k + 1, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = min(i, k); j >= 2; --j) {
                dp[j] = (j * dp[j] + dp[j - 1]) % MOD;
            }
        }
        return dp[k];
    }
};
