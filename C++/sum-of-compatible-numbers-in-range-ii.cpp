// Time:  O(log(n + k))
// Space: O(1)

// digit dp
class Solution {
public:
    int sumOfGoodIntegers(long long n, long long k) {
        static const int64_t MOD = 1e9 + 7;

        const auto& count = [&](uint64_t x) {
            const auto& l = bit_width(x);
            uint64_t mask = ((1ULL << l) - 1) & (~static_cast<uint64_t>(n));
            int c = popcount(mask);
            uint64_t result = 0, prefix = 0;
            for (int i = l - 1; i >= 0; --i) {
                if (mask & (1ULL << i)) {
                    mask ^= 1ULL << i;
                    --c;
                }
                if ((x & (1ULL << i)) == 0) {
                    continue;
                }
                result = (((result + (((prefix % MOD) * ((1ULL << c) % MOD)) % MOD)) % MOD) + (((mask % MOD) * (((1ULL << c) >> 1) % MOD)) % MOD)) % MOD;
                if (n & (1ULL << i)) {
                    return result;
                }
                prefix |= 1ULL << i;
            }
            return (result + x) % MOD;
        };

        return (count(n + k) - count(max(n - k, 1LL) - 1) + MOD) % MOD;
    }
};
