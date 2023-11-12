// Time:  O(logn)
// Space: O(1)

// combinatorics, principle of inclusion-exclusion
class Solution {
public:
    int stringCount(int n) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [](uint64_t a, uint64_t b, uint64_t mod) {
            a %= mod;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a % mod);
                }
                a = (a * a % mod);
                b >>= 1;
            }
            return result;
        };
    
        return  ((powmod(26, n, MOD) - 
                 (25 + 25 + 25 + n) * powmod(25, n - 1, MOD) +                   // no l, t, e, ee
                 (24 + 24 + 24 + n + n + 0) * powmod(24, n - 1, MOD) -           // no l|t, l|e, t|e, l|ee, t|ee, e|ee
                 (23 + n + 0 + 0) * powmod(23, n - 1, MOD)) % MOD + MOD) % MOD;  // no l|t|e, l|t|ee, l|e|ee, t|e|ee    
    }
};

// Time:  O(2^4 * n) = O(n)
// Space: O(2^4) = O(1)
// bitmasks, dp
class Solution2 {
public:
    int stringCount(int n) {
        static const int MOD = 1e9 + 7;

        enum {L = 1 << 0, E = 1 << 1, EE = 1 << 2, T = 1 << 3};
        vector<int64_t> dp(1 << 4);
        dp[0] = 1;
        for (int _ = 0; _ < n; ++_) {
            vector<int64_t> new_dp(1 << 4);
            for (int mask = 0; mask < size(dp); ++mask) {
                new_dp[mask | L] = (new_dp[mask | L] + dp[mask]) % MOD;
                if ((mask & E) == 0) {
                    new_dp[mask | E] = (new_dp[mask|E] + dp[mask]) % MOD;
                } else {
                    new_dp[mask | EE] = (new_dp[mask | EE] + dp[mask]) % MOD;
                }
                new_dp[mask | T] = (new_dp[mask | T] + dp[mask]) % MOD;
                new_dp[mask] = (new_dp[mask] + 23 * dp[mask]) % MOD;
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
