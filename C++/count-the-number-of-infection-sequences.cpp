// Time:  precompute: O(max_n)
//        runtime:    O(s + logn)
// Space: O(max_n)

// combinatorics
vector<int> FACT = {1, 1};
vector<int> INV = {1, 1};
vector<int> INV_FACT = {1, 1};
class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int result = 1, total = 0, cnt = 0;
        for (int i = 0; i <= size(sick); ++i) {
            const int l = (i < size(sick) ? sick[i] : n) - (i - 1 >= 0 ? sick[i - 1] : -1) - 1;
            if (i != 0 && i != size(sick)) {
                cnt += max(l - 1, 0);
            }
            total += l;
            result = mulmod(result, nCr(total, l));
        }
        result = mulmod(result, powmod(2, cnt));
        return result;
    }

private:
    int nCr(int n, int k) {
        while (size(INV) <= n) {  // lazy initialization
            FACT.emplace_back(mulmod(FACT.back(), size(INV)));
            INV.emplace_back(mulmod(INV[MOD % size(INV)], MOD - MOD / size(INV)));  // https://cp-algorithms.com/algebra/module-inverse.html
            INV_FACT.emplace_back(mulmod(INV_FACT.back(), INV.back()));
        }
        return mulmod(mulmod(FACT[n], INV_FACT[n - k]), INV_FACT[k]);
    }

    uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
        a %= MOD, b %= MOD;
        if (MOD - a <= b) {
            b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
        a %= MOD, b %= MOD;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b)  { 
            if (b & 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b >>= 1;
        } 
        return result; 
    }

    uint32_t powmod(uint32_t a, uint32_t b) {
        a %= MOD;
        uint32_t result = 1;
        while (b) {
            if (b & 1) {
                result = mulmod(result, a);
            }
            a = mulmod(a, a);
            b >>= 1;
        }
        return result;
    }
   
    static const uint32_t MOD = 1e9 + 7;
};
