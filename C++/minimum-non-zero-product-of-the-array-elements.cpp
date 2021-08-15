// Time:  O(min(p, logM))
// Space: O(1)

class Solution {
public:
    int minNonZeroProduct(int p) {
        static const int MOD = 1e9 + 7;
        // max_num = 2^p-1
        uint32_t max_num_mod = submod(powmod(2, p, MOD), 1, MOD);  // max_num % MOD

        // pair_num = max_num-1
        uint32_t pair_product_mod = submod(max_num_mod, 1, MOD); // (max_num_mod-1) % MOD

        // since pair_product^MOD % MOD = pair_product_mod^MOD % MOD  = pair_product_mod
        // => pair_product_mod^(MOD-1) % MOD = 1
        // => pair_product_mod^(pair_cnt) % MOD = pair_product_mod^(pair_cnt%(MOD-1)) %MOD
        uint32_t pair_cnt_mod_m_1 = submod(powmod(2, p - 1, MOD - 1), 1, MOD - 1);  // pair_cnt%(MOD-1)

        // the ans is:
        //   max_num * pair_num^pair_cnt % MOD
        // = max_num_mod * pair_product_mod^(pair_cnt_mod_m_1) % MOD
        return mulmod(max_num_mod, powmod(pair_product_mod, pair_cnt_mod_m_1, MOD), MOD);
    }

private:
    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        // a %= mod, b %= mod;  // assumed a, b have been mod
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }
    
    uint32_t submod(uint32_t a, uint32_t b, uint32_t mod) {
        // a %= mod, b %= mod;  // assumed a, b have been mod
        return addmod(a, mod - b, mod);
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
