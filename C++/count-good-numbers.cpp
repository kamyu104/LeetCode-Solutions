// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int countGoodNumbers(long long n) {
        static const int MOD = 1e9 + 7;
        return int64_t(powmod(5, (n + 1) / 2 % (MOD - 1), MOD)) * powmod(4, n / 2 % (MOD - 1), MOD) % MOD;
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};
