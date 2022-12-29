// Time:  O(n * k)
// Space: O(k)

// knapsack dp
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;

        if (accumulate(cbegin(nums), cend(nums), 0ll) < 2 * k) {
            return 0;
        }
        int result = 1;
        vector<int> dp(k);
        dp[0] = 1;
        for (const auto& x : nums) {
            for (int i = k - 1 - x; i >= 0; --i) {
                dp[i + x] = (dp[i + x] + dp[i]) % MOD;
            }
            result = (result * 2) % MOD;
       }
       return ((result - 2 * accumulate(cbegin(dp), cend(dp), 0, [&](const auto& total, const auto& x) {
           return (total + x) % MOD;
       })) % MOD + MOD) % MOD;
    }
};
