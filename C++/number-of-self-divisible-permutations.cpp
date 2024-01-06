// Time:  O(n^2 * logn + n * 2^n) = O(n * 2^n)
// Space: O(n^2 + 2^n) = O(2^n)

// bitmasks, dp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        vector<vector<bool>> lookup(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                lookup[i][j] = lookup[j][i] = gcd(i + 1, j + 1) == 1;
            }
        }
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            const int i = __builtin_popcount(mask);
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) == 0 && lookup[i][j]) {
                    dp[mask | (1 << j)] += dp[mask];
                }
            }
        }
        return dp.back();
    }
};
