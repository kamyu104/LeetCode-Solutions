// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        static const int MOD = 1e9 + 7;

        for (int64_t i = n - 1; i >= 0; --i) {
            const int64_t base = 1ll << i;
            if ((min(a, b) & base) == 0) {
                a ^= base;
                b ^= base;
            }
        }
        return (a % MOD) * (b % MOD) % MOD;
    }
};
