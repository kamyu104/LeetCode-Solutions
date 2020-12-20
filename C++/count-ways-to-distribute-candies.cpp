// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int waysToDistribute(int n, int k) {
        static int MOD = 1e9 + 7;
        vector<int64_t> dp(k, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = min(i, k) - 1; j >= 1; --j) {
                dp[j] = ((j + 1) * dp[j] + dp[j - 1]) % MOD;
            }
        }
        return dp[k - 1];
    }
};
