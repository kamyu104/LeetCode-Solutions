// Time:  O(n + logm)
// Space: O(n)

// combinatorics, fast exponentiation
static const int MOD = 1e9 + 7;
vector<int64_t> FACT = {1, 1};
vector<int64_t> INV = {1, 1};
vector<int64_t> INV_FACT = {1, 1};
int nCr(int n, int k) {
    while (size(INV) <= n) {  // lazy initialization
        FACT.emplace_back((FACT.back() *size(INV)) % MOD);
        INV.emplace_back(((INV[MOD % size(INV)]) * (MOD - MOD / size(INV))) % MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.emplace_back((INV_FACT.back() * INV.back()) % MOD);
    }
    return (((FACT[n] * INV_FACT[n - k]) % MOD) * INV_FACT[k]) % MOD;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const auto& powmod = [&](int a, int b) {
            a %= MOD;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % MOD;
                }
                a = int64_t(a) * a % MOD;
                b >>= 1;
            }
            return result;
        };

        return (nCr(n - 1, k) * (m * powmod(m - 1, (n - 1) - k) % MOD)) % MOD;
    }
};
