// Time:  O(n^2 * 2^n * logn)
// Space: O(2^n)

// dp
class Solution {
public:
    int selfDivisiblePermutationCount(int n) {
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(1 << n);
            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int j = 0; j < n; ++j) {
                    if ((mask & (1 << j)) && gcd(j + 1, i + 1) == 1) {
                        new_dp[mask] += dp[mask ^ (1 << j)];
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
