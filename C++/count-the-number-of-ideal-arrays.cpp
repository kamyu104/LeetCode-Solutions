// Time:  O(nlogm + n * sqrt(m) / log(sqrt(m)))
// Space: O(sqrt(m))

// dp, factorization, combinatorics
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        static const vector<int> PRIMES = linear_sieve_of_eratosthenes(sqrt(1e4));
        int result = 0;
        for (int i = 1; i <= maxValue; ++i) {
            int x = i;
            unordered_map<int, int> dp;
            for (const auto& p : PRIMES) {
                if (x < p) {
                    break;
                }
                for (; x % p == 0; x /= p) {
                    ++dp[p];
                }
            }
            if (x != 1) {
                ++dp[x];
            }
            int64_t total = 1;
            for (const auto& [k, v] : dp) {
                total = mulmod(total, nCr(n + v - 1, v));  // H(n, v) = nCr(n + v - 1, n)
            }
            result = addmod(result, total);
        }
        return result;
    }

private:
    int nCr(int n, int k) {
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

    vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
        vector<int> spf(n + 1);
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.emplace_back(i);
            }
            for (const auto& p : primes) {
                if (i * p > n || p > spf[i]) {
                    break;
                }
                spf[i * p] = p;
            }
        }
        return primes;
    }
    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};

// Time:  O(n * mlogm)
// Space: O(n + m)
// dp, combinatorics
class Solution2 {
public:
    int idealArrays(int n, int maxValue) {
        int result = 0;
        unordered_map<int, int> dp;
        for (int i = 1; i <= maxValue; ++i) {
            dp[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> new_dp;
            int total = 0;
            for (const auto& [x, c] : dp) {
                total = addmod(total, c);
                for (int y = x + x; y <= maxValue; y += x) {
                    new_dp[y] += c;
                }
            }
            result = addmod(result, mulmod(total , nCr(n - 1, i)));
            dp = move(new_dp);
        }
        return result;
    }

private:
    int nCr(int n, int k) {
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
