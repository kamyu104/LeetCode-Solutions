// Time:  O(logn)
// Space: O(1)

// combinatorics
class Solution {
public:
    int countDistinctStrings(string s, int k) {
        static const int MOD = 1e9 + 7;
        return powmod(2, size(s) - k + 1, MOD);
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
