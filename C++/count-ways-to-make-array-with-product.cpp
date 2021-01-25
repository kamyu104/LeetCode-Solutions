// Time:  O(nlogn)
// Space: O(logn)

class Solution {
public:
    Solution()
     : fact_((MAX_F + MAX_N - 1) + 1)
     , inv_((MAX_F + MAX_N - 1) + 1)
     , inv_fact_((MAX_F + MAX_N - 1) + 1)
     , sieve_(MAX_N + 1) {

        fact_[0] = inv_fact_[0] = fact_[1] = inv_fact_[1] = inv_[1] = 1;
        for (int i = 2; i < size(fact_); ++i) {
            fact_[i] = mulmod(fact_[i - 1], i, MOD);
            inv_[i] = mulmod(inv_[MOD % i], MOD - MOD / i, MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_[i] = mulmod(inv_fact_[i - 1], inv_[i], MOD);
        }

        iota(begin(sieve_), end(sieve_), 0);
        for (int i = 2; i <= MAX_N; ++i) {
            if (sieve_[i] != i) {
                continue;
            }
            for (int j = i * i; j <= MAX_N; j += i) {
                sieve_[j] = i;
            }
        }
    }

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> result;
        for (const auto& q : queries) {
            const int n = q[0], k = q[1];
            const auto& factors = get_factors(k);
            int curr = 1;
            for (const auto& [p, f] : factors) {
                curr = mulmod(curr, nCr(f + n - 1, f, MOD), MOD);  // H(n, f)
            }
            result.emplace_back(curr);
        }
        return result;
    }

private:
    unordered_map<int, int> get_factors(int k) {
        unordered_map<int, int> factors;
        while (k > 1) {
            ++factors[sieve_[k]];
            k /= sieve_[k];
        }
        return factors;
    }

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
    static const int MAX_N = 10000;
    static const int MAX_F = 13;  // floor(log2(MAX_N));

    vector<int> fact_;
    vector<int> inv_;
    vector<int> inv_fact_;
    vector<int> sieve_;
};
