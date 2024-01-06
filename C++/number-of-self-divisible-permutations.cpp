// Time:  O(n^2 * logn + n * 2^n) = O(n * 2^n)
// Space: O(n^2 + 2^n) = O(2^n)

// bitmasks, dp, memoization
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        vector<vector<int>> lookup(n, vector<int>(n));
        const auto& memoization = [&](int a, int b) {
            if (a > b) {
                swap(a, b);
            }
            if (!lookup[a - 1][b - 1]) {
                lookup[a - 1][b - 1] = gcd(a, b);
            }
            return lookup[a - 1][b - 1];
        };
        
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            const int i = __builtin_popcount(mask);
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) == 0 && memoization(j + 1, i + 1) == 1) {
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
        return dp.back();
    }
};
