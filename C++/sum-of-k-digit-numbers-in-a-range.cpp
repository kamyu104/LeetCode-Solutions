// Time:  O(logr), r = MOD
// Space: O(1)

// math
class Solution {
public:
    int sumOfNumbers(int l, int r, int k) {
        static const uint32_t MOD = 1e9 + 7;

        const auto& addmod = [](uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
            // a %= mod, b %= mod;  // assumed a, b have been mod
            if (mod - a <= b) {
                b -= mod;  // relied on unsigned integer overflow in order to give the expected results
            }
            return a + b;
        };

        const auto& submod = [&](uint32_t a, uint32_t b, uint32_t mod) {
            // a %= mod, b %= mod;  // assumed a, b have been mod
            return addmod(a, mod - b, mod);
        };

        const auto& mulmod = [&](uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
            // a %= mod, b %= mod;  // assumed a, b have been mod
            uint32_t result = 0;
            if (a < b) {
                swap(a, b);
            }
            while (b > 0)  { 
                if (b % 2 == 1) {
                    result = addmod(result, a, mod);
                }
                a = addmod(a, a, mod);
                b /= 2; 
            } 
            return result; 
        };

        const auto& powmod = [&](uint32_t a, uint32_t b, uint32_t mod) {
            a %= mod;
            uint32_t result = 1;
            while (b) {
                if (b & 1) {
                    result = mulmod(result, a, mod);
                }
                a = mulmod(a, a, mod);
                b >>= 1;
            }
            return result;
        };

        const auto& invmod = [&](uint32_t x, uint32_t mod) {
            return powmod(x, mod - 2, mod);
        };

        return mulmod(mulmod((r + l) * (r - l + 1) / 2, powmod(r - l + 1, k - 1, MOD), MOD),
                      mulmod(submod(powmod(10, k, MOD), 1, MOD), invmod(10 - 1, MOD), MOD), MOD);
    }
};
