// Time:  O(1), excluding precomputation time
// Space: O(n)

class Solution {
public:
    Solution()
     : fact_(2 * MAX_N - 1 + 1)
     , inv_(2 * MAX_N - 1 + 1)
     , inv_fact_(2 * MAX_N - 1 + 1) {

        fact_[0] = inv_fact_[0] = fact_[1] = inv_fact_[1] = inv_[1] = 1;
        for (int i = 2; i < size(fact_); ++i) {
            fact_[i] = mulmod(fact_[i - 1], i, MOD);
            inv_[i] = mulmod(inv_[MOD % i], MOD - MOD / i, MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_[i] = mulmod(inv_fact_[i - 1], inv_[i], MOD);
        }
    }

    int numberOfSets(int n, int k) {
        // find k segments with 1+ length and (k+1) spaces with 0+ length s.t. total length is n-1
        // => find k segments with 0+ length and (k+1) spaces with 0+ length s.t. total length is n-k-1
        // => find the number of combinations of 2k+1 variables with total sum n-k-1
        // => H(2k+1, n-k-1)
        // => C((2k+1) + (n-k-1) - 1, n-k-1)
        // => C(n+k-1, n-k-1) = C(n+k-1, 2k)
        return nCr(n + k - 1, 2 * k, MOD);
    }

private:
    int nCr(int n, int k, uint32_t mod) {
        return mulmod(mulmod(fact_[n], inv_fact_[n - k], mod), inv_fact_[k], mod);
    }

    uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
        a %= mod, b %= mod;
        if (mod - a <= b) {
            b -= mod;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
        a %= mod, b %= mod;
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
    
    static const int MOD = 1e9 + 7;
    static const int MAX_N = 1000;
    vector<int> fact_;
    vector<int> inv_;
    vector<int> inv_fact_;
};
