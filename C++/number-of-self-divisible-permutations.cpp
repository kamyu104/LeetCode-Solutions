// Time:  O(n * 2^n * logn)
// Space: O(2^n)

// dp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            const int i = __builtin_popcount(mask);
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) == 0 && gcd(j + 1, i + 1) == 1) {
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
        return dp.back();
    }
};
