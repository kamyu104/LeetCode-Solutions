// Time:  precompute: O(max(m * n))
//        runtime:    O(1)
// Space: O(max(m * n))

// combinatorics
static const uint32_t MOD = 1e9 + 7;

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
int nCr(int n, int k) {
    while (size(INV) <= n) {  // lazy initialization
        FACT.emplace_back(mulmod(FACT.back(), size(INV)));
        INV.emplace_back(mulmod(INV[MOD % size(INV)], MOD - MOD / size(INV)));  // https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.emplace_back(mulmod(INV_FACT.back(), INV.back()));
    }
    return mulmod(mulmod(FACT[n], INV_FACT[n - k]), INV_FACT[k]);
}

class Solution {
public:
    int distanceSum(int m, int n, int k) {
        const auto& sum_n = [](int n) {
            return static_cast<int64_t>(n + 1) * n / 2;
        };

        const auto& sum_n_square = [](int n) {
            return static_cast<int64_t>(n) * (n + 1) * (2 * n + 1) / 6;
        };

        const auto& f = [&](int n) {
            // sum((d*(n-d) for d in xrange(1, n)))
            return (n * sum_n(n - 1) - sum_n_square(n - 1)); 
        };

        const auto x = mulmod(mulmod(f(n) % MOD, m), m);
        const auto y = mulmod(mulmod(f(m) % MOD, n), n);
        return mulmod(x + y, nCr(m * n - 2, k - 2));
    }
};
