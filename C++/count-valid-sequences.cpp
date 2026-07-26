// Time:  O(n)
// Space: O(n)

// stars and bars, combinatorics
static const uint32_t MOD = 1e9 + 7;

uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
    if (MOD - a <= b) {
        b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
    }
    return a + b;
}

uint32_t submod(uint32_t a, uint32_t b) {
    return addmod(a, (MOD - b) % MOD);
}

// reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
    uint32_t result = 0;
    if (a < b) {
        swap(a, b);
    }
    while (b > 0)  { 
        if (b & 1) {
            result = addmod(result, a);
        }
        a = addmod(a, a);
        b >>= 1;
    } 
    return result; 
} 

vector<int> FACT = {1, 1};
vector<int> INV = {1, 1};
vector<int> INV_FACT = {1, 1};
const int MAX_N = 5e5;
const auto& init = [](int n) {
    while (size(INV) <= n) {  // lazy initialization
        FACT.emplace_back(mulmod(FACT.back(), size(INV)));
        INV.emplace_back(mulmod(INV[MOD % size(INV)], MOD - MOD / size(INV)));  // https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.emplace_back(mulmod(INV_FACT.back(), INV.back()));
    }
    return 0;
}(MAX_N);

class Solution {
public:
    int countValidSequences(int n, int k) {
        const auto& nCr = [](int n, int k) {
            return mulmod(mulmod(FACT[n], INV_FACT[n - k]), INV_FACT[k]);
        };

        const auto& nHr = [&](int n, int k) {
            return nCr(n + k - 1, k);
        };

        return submod(nHr(k, n - k), (n - k) % 2 == 0 ? nHr(k, (n - k) / 2) : 0);
    }
};
