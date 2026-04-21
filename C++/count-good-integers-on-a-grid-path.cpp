// Time:  O(16 * 2 * 10 * 10)
// Space: O(16 + 2 * 10)

// dp
class Solution {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        static const int L = 16;

        vector<bool> lookup(L);
        const auto& count = [&](int64_t n) {
            vector<int> digits(L);
            for (int i = L - 1; i >= 0; --i) {
                digits[i] = n % 10;
                n /= 10;
            }
            int64_t dp[2][10] = {};
            dp[1][0] = 1;
            for (int i = 0; i < L; ++i) {
                int64_t new_dp[2][10] = {};
                for (int t = 0; t < 2; ++t) {
                    const auto& bound = t ? digits[i] : 9;
                    for (int k = 0; k < 10; ++k) {
                        if (!dp[t][k]) {
                            continue;
                        }
                        for (int d = 0; d <= bound; ++d) {
                            int nk = k;
                            if (lookup[i]) {
                                if (d < k) {
                                    continue;
                                }
                                nk = d;
                            }
                            new_dp[t && d == bound][nk] += dp[t][k];
                        }
                    }
                }
                for (int t = 0; t < 2; ++t) {
                    for (int k = 0; k < 10; ++k) {
                        dp[t][k] = new_dp[t][k];
                    }
                }
            }
            int64_t result = 0;
            for (int t = 0; t < 2; ++t) {
                for (int k = 0; k < 10; ++k) {
                    result += dp[t][k];
                }
            }
            return result;
        };

        int i = 0, j = 0;
        lookup[i * 4 + j] = true;
        for (const auto& x : directions) {
            if (x == 'D') {
                ++i;
            } else {
                ++j;
            }
            lookup[i * 4 + j] = true;
        }
        return count(r) - count(l - 1);
    }
};

// Time:  O(16 * 2 * 10 * 10)
// Space: O(16 + 2 * 10)
// dp
class Solution2 {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        static const int L = 16;

        vector<bool> lookup(L);
        const auto& count = [&](int64_t n) {
            vector<int> digits(L);
            for (int i = L - 1; i >= 0; --i) {
                digits[i] = n % 10;
                n /= 10;
            }
            vector<vector<int64_t>> dp(2, vector<int64_t>(10));
            dp[1][0] = 1;
            for (int i = 0; i < L; ++i) {
                vector<vector<int64_t>> new_dp(2, vector<int64_t>(10));
                for (int t = 0; t < 2; ++t) {
                    const auto& bound = t ? digits[i] : 9;
                    for (int k = 0; k < 10; ++k) {
                        if (!dp[t][k]) {
                            continue;
                        }
                        for (int d = 0; d <= bound; ++d) {
                            int nk = k;
                            if (lookup[i]) {
                                if (d < k) {
                                    continue;
                                }
                                nk = d;
                            }
                            new_dp[t && d == bound][nk] += dp[t][k];
                        }
                    }
                }
                dp = move(new_dp);
            }
            int64_t result = 0;
            for (const auto& row : dp) {
                result += accumulate(cbegin(row), cend(row), 0LL);
            }
            return result;
        };

        int i = 0, j = 0;
        lookup[i * 4 + j] = true;
        for (const auto& x : directions) {
            if (x == 'D') {
                ++i;
            } else {
                ++j;
            }
            lookup[i * 4 + j] = true;
        }
        return count(r) - count(l - 1);
    }
};

// Time:  O(16 * 10 * 10)
// Space: O(16 * 10)
// memoization
class Solution3 {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        static const int L = 16;

        const auto& count = [&](int64_t n) {
            vector<bool> lookup(L);
            vector<int> digits(L);
            vector<vector<int64_t>> memo(L, vector<int64_t>(10, -1));
            const auto memoization = [&](this auto&& memoization, int i, bool t, int k) -> int64_t {
                if (i == 16) {
                    return 1;
                }
                if (!t && memo[i][k] != -1) {
                    return memo[i][k];
                }
                int64_t result = 0;
                const auto& bound = t ? digits[i] : 9;
                for (int d = 0; d <= bound; ++d) {
                    int nk = k;
                    if (lookup[i]) {
                        if (d < k) {
                            continue;
                        }
                        nk = d;
                    }
                    result += memoization(i + 1, t && (d == bound), nk);
                }
                if (!t) {
                    memo[i][k] = result;
                }
                return result;
            };
            
            for (int i = L - 1; i >= 0; --i) {
                digits[i] = n % 10;
                n /= 10;
            }
            int i = 0, j = 0;
            lookup[i * 4 + j] = true;
            for (const auto& x : directions) {
                if (x == 'D') {
                    ++i;
                } else {
                    ++j;
                }
                lookup[i * 4 + j] = true;
            }
            return memoization(0, true, 0);
        };

        return count(r) - count(l - 1);
    }
};

// Time:  O(16 * 2 * 10 * 10)
// Space: O(16 * 2 * 10)
// memoization
class Solution4 {
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        static const int L = 16;

        const auto& count = [&](int64_t n) {
            vector<bool> lookup(L);
            vector<int> digits(L);
            vector<vector<vector<int64_t>>> memo(L, vector<vector<int64_t>>(2, vector<int64_t>(10, -1)));
            const auto memoization = [&](this auto&& memoization, int i, bool t, int k) -> int64_t {
                if (i == 16) {
                    return 1;
                }
                if (memo[i][t][k] == -1) {
                    memo[i][t][k] = 0;
                    const auto& bound = t ? digits[i] : 9;
                    for (int d = 0; d <= bound; ++d) {
                        int nk = k;
                        if (lookup[i]) {
                            if (d < k) {
                                continue;
                            }
                            nk = d;
                        }
                        memo[i][t][k] += memoization(i + 1, t && (d == bound), nk);
                    }
                }
                return memo[i][t][k];
            };
            
            for (int i = L - 1; i >= 0; --i) {
                digits[i] = n % 10;
                n /= 10;
            }
            int i = 0, j = 0;
            lookup[i * 4 + j] = true;
            for (const auto& x : directions) {
                if (x == 'D') {
                    ++i;
                } else {
                    ++j;
                }
                lookup[i * 4 + j] = true;
            }
            return memoization(0, true, 0);
        };

        return count(r) - count(l - 1);
    }
};
