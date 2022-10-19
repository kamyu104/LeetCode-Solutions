// Time:  O(logn + qlogr), r = MOD
// Space: O(logn)

// prefix sum
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;

        vector<int> prefix(1);
        for (int i = 0; (1 << i) <= n; ++i) {
            if ((1 << i) & n) {
                prefix.push_back(prefix.back() + i);
            }
        }
        vector<int> result;
        for (const auto& q : queries) {
            result.emplace_back(powmod(2, prefix[q[1] + 1] - prefix[q[0]], MOD));
        }
        return result;
    }

private:
    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        // a %= mod, b %= mod;  // assumed a, b have been mod
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
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
    }

    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
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
    }
};
