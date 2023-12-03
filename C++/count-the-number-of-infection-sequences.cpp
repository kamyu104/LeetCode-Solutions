// Time:  O(n)
// Space: O(n)

vector<int> fact = {1, 1};
vector<int> inv = {1, 1};
vector<int> inv_fact = {1, 1};

// combinatorics
class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int result = 1, total = 0;
        for (int i = 0; i <= size(sick); ++i) {
            const int l = (i < size(sick) ? sick[i] : n) - (i - 1 >= 0 ? sick[i - 1] : -1) - 1;
            if (i != 0 && i != size(sick)) {
                result = mulmod(result, powmod(2, max(l - 1, 0)));
            }
            total += l;
            result = mulmod(result, nCr(total, l));
        }
        return result;
    }

private:
    int nCr(int n, int k) {
        while (size(inv) <= n) {  // lazy initialization
            fact.emplace_back(mulmod(fact.back(), size(inv)));
            inv.emplace_back(mulmod(inv[MOD % size(inv)], MOD - MOD / size(inv)));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact.emplace_back(mulmod(inv_fact.back(), inv.back()));
        }
        return mulmod(mulmod(fact[n], inv_fact[n - k]), inv_fact[k]);
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
        while (b > 0)  { 
            if (b % 2 == 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b /= 2; 
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
