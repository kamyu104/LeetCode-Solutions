// Time:  O(n * k * m^2)
// Space: O(k * m^2)

// dp, combinatorics
class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        while (size(inv_) <= m) {
            fact_.emplace_back(mulmod(fact_.back(), size(inv_)));
            inv_.emplace_back(mulmod(inv_[MOD % size(inv_)], MOD - MOD / size(inv_)));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back()));
        }
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(k + 1, vector<int>(m + 1)));  // dp[c][b][l]: sum of carry c with b set bits with remain size of l
        dp[0][0][m] = 1;
        for (const auto& x : nums) {
            vector<vector<vector<int>>> new_dp(m + 1, vector<vector<int>>(k + 1, vector<int>(m + 1)));
            for (int c = 0; c <= m; ++c) {
                for (int b = 0; b <= k; ++b) {
                    for (int l = 0; l <= m; ++l) {
                        if (!dp[c][b][l]) {
                            continue;
                        }
                        int base = 1;
                        for (int cnt = 0; cnt <= l; ++cnt) {
                            const int nc = (c + cnt) >> 1;
                            const int nb = b + ((c + cnt) & 1);
                            const int nl = l - cnt;
                            if (nb > k) {
                                continue;
                            }
                            new_dp[nc][nb][nl] = addmod(new_dp[nc][nb][nl], mulmod(mulmod(dp[c][b][l], base), inv_fact_[cnt]));
                            base = mulmod(base, x);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (int c = 0; c <= m; ++c) {
            const int b = k - __builtin_popcount(c);
            if (b >= 0) {
                result = addmod(result, dp[c][b][0]);
            }
        }
        result = mulmod(result, fact_[m]);
        return result;
    }

private:
    uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
        // a %= MOD, b %= MOD;
        if (MOD - a <= b) {
            b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
        // a %= MOD, b %= MOD;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if ((b & 1) == 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b >>= 1;
        } 
        return result; 
    }
   
    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};

// Time:  O(n * k * m^2)
// Space: O(k * m^2)
// dp, combinatorics
class Solution2 {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        while (size(inv_) <= m) {
            fact_.emplace_back(mulmod(fact_.back(), size(inv_)));
            inv_.emplace_back(mulmod(inv_[MOD % size(inv_)], MOD - MOD / size(inv_)));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back()));
        }
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(k + 1, vector<int>(m + 1)));  // dp[c][b][l]: sum of carry c with b set bits with remain size of l
        dp[0][0][m] = 1;
        for (const auto& x : nums) {
            vector<vector<vector<int>>> new_dp(m + 1, vector<vector<int>>(k + 1, vector<int>(m + 1)));
            for (int c = 0; c <= m; ++c) {
                for (int b = 0; b <= k; ++b) {
                    for (int l = 0; l <= m; ++l) {
                        if (!dp[c][b][l]) {
                            continue;
                        }
                        int base = 1;
                        for (int cnt = 0; cnt <= l; ++cnt) {
                            const int nc = (c + cnt) >> 1;
                            const int nb = b + ((c + cnt) & 1);
                            const int nl = l - cnt;
                            if (nb > k) {
                                continue;
                            }
                            new_dp[nc][nb][nl] = addmod(new_dp[nc][nb][nl], mulmod(mulmod(dp[c][b][l], base), nCr(l, cnt)));
                            base = mulmod(base, x);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (int c = 0; c <= m; ++c) {
            const int b = k - __builtin_popcount(c);
            if (b >= 0) {
                result = addmod(result, dp[c][b][0]);
            }
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
        // a %= MOD, b %= MOD;
        if (MOD - a <= b) {
            b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
        // a %= MOD, b %= MOD;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  { 
            if ((b & 1) == 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b >>= 1;
        } 
        return result; 
    }
   
    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};
