// Time:  O(logn)
// Space: O(1)

// combinatorics, fast exponentiation
class Solution {
public:
    int monkeyMove(int n) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [&](int a, int b) {
            a %= MOD;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % MOD;
                }
                a = int64_t(a) * a % MOD;
                b >>= 1;
            }
            return result;
        };

        return ((powmod(2, n) - 2) + MOD) % MOD;
    }
};
