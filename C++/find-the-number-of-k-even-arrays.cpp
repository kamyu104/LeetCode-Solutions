// Time:  O(n)
// Space: O(n)

// stars and bars, combinatorics
class Solution {
public:
    int countOfArrays(int n, int m, int k) {
        const int even = m / 2, odd = (m + 1) / 2;
        int result = 0;
        if (k == 0) {
            result = (result + pow(odd, n)) % MOD;
        }
        for (int x = 1; x <= (n + 1 - k) / 2; ++x) {  // since (n-(k+x))-((x+1)-2) >= 0, so x <= (n+1-k)/2
            const auto a = static_cast<int64_t>(nHr(x, (k + x) - x)) * nHr(x + 1, (n - (k + x)) - ((x + 1) - 2)) % MOD;
            const auto b = static_cast<int64_t>(pow(even, k + x)) * pow(odd, n - (k + x)) % MOD;
            result = (result + (a * b) % MOD) % MOD;
        }
        return result;
    }

private:
    int nHr(int n, int k) {
        return nCr(n + k - 1, k);
    }

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

    int pow(int a, int b) {
        while (b >= size(pow_[a])) {
            pow_[a].emplace_back(!empty(pow_[a]) ? (static_cast<int64_t>(pow_[a].back()) * a) % MOD : 1);
        }
        return pow_[a][b];
    }

    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
    unordered_map<int, vector<int>> pow_;
};

// Time:  O(n * k)
// Space: O(k)
// dp
class Solution2 {
public:
    int countOfArrays(int n, int m, int k) {
        static const int MOD = 1e9 + 7;

        const int even = m / 2, odd = (m + 1) / 2;
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[0][0] = even;
        dp[1][0] = odd;
        for (int _ = 0; _ < n - 1; ++_) {
            for (int i = k; i >= 0; --i) {
                tie(dp[0][i], dp[1][i]) = pair((static_cast<int64_t>((i - 1 >= 0 ? dp[0][i - 1] : 0) + dp[1][i]) * even) % MOD,
                                               (static_cast<int64_t>(dp[0][i] + dp[1][i]) * odd) % MOD);
            }
        }
        return (dp[0][k] + dp[1][k]) % MOD;
    }
};
