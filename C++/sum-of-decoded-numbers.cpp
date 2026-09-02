// Time:  O(nlogr)
// Space: O(1)

// fast exponentiation
class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        static const int MOD = 1e9 + 7;
        const auto& powmod = [](uint32_t a, uint32_t b, uint32_t mod) {
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
        };

        const auto& length = [](int64_t x) {
            int result = 0;
            for (; x; x /= 10) {
                ++result;
            }
            return result;
        };

        int result = 0;
        for (const auto& v : nums) {
            const auto& d = v / 10, &w = v % 10;
            const int64_t base = pow(10, length(d) - w);
            const auto& x = d / base, &y = d % base;
            result = (result + powmod(x, y, MOD)) % MOD;
        }
        return result;
    }
};
