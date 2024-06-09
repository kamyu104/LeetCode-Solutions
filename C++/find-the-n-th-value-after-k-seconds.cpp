// Time:  O(n + k)
// Space: O(n + k)

// combinatorics
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        return nCr((n - 1) + k, n - 1);
    }

private:
    int nCr(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        while (size(inv_) <= n) {  // lazy initialization
            fact_.emplace_back(mulmod(fact_.back(), size(inv_)));
            inv_.emplace_back(mulmod(inv_[MOD % size(inv_)], MOD - MOD / size(inv_)));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back()));
        }
        return mulmod(mulmod(fact_[n], inv_fact_[n - k]), inv_fact_[k]);
    }

    uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
        a %= MOD, b %= MOD;
        if (MOD - a <= b) {
            b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    uint32_t submod(uint32_t a, uint32_t b) {
        a %= MOD, b %= MOD;
        return addmod(a, MOD - b);
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
        a %= MOD, b %= MOD;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if (b % 2 == 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b /= 2; 
        } 
        return result; 
    }
   
    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};

// Time:  O(n * k)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    int valueAfterKSeconds(int n, int k) {
        static const uint32_t MOD = 1e9 + 7;

        vector<int> prefix(n, 1);
        for (int _ = 0; _ < k; ++_) {
            for (int i = 1; i < n; ++i) {
                prefix[i] = (prefix[i] + prefix[i - 1]) % MOD;
            }
        }
        return prefix.back();
    }
};
