// Time:  O((logn)^2)
// Space: O(logn)

// dp
class Solution {
public:
    long long countBalanced(long long low, long long high) {
        const auto& count = [&](int64_t n) {
            vector<int> digits;
            for (; n; n /= 10) {
                digits.emplace_back(n % 10);
            }
            ranges::reverse(digits);
            const auto& shift = size(digits) / 2 * 9;
            vector<vector<int64_t>> dp(size(digits) * 9 + 1, vector<int64_t>(2));
            dp[shift][1] = 1;
            for (int i = 0; i < size(digits); ++i) {
                vector<vector<int64_t>> new_dp(size(digits) * 9 + 1, vector<int64_t>(2));
                for (int curr = 0; curr < size(dp); ++curr) {
                    for (int tight = 0; tight <= 1; ++tight) {
                        if (dp[curr][tight] == 0) {
                            continue;
                        }                        
                        for (int d = 0, bound = tight ? digits[i] : 9; d <= bound; ++d) {
                            new_dp[(i & 1) ? curr - d : curr + d][tight && d == bound] += dp[curr][tight];
                        }
                    }
                }
                dp = move(new_dp);
            }
            
            return dp[shift][0];
        };
        
        return count(high + 1) - count(low);
    }
};

// Time:  O((logn)^2)
// Space: O((logn)^2)
// memoization
class Solution2 {
public:
    long long countBalanced(long long low, long long high) {
        const auto& count = [&](int64_t n) {
            vector<int> digits;
            for (; n; n /= 10) {
                digits.emplace_back(n % 10);
            }
            ranges::reverse(digits);
            vector<vector<int64_t>> memo(size(digits), vector<int64_t>(size(digits) * 9 + 1, -1));
            const int shift = size(digits) / 2 * 9;
            const auto memoization = [&](this auto&& memoization, int i, int curr, bool tight) -> int64_t {
                if (i == size(digits)) {
                    return curr == shift;
                }
                if (!tight && memo[i][curr] != -1) {
                    return memo[i][curr];
                }
                const auto& bound = tight ? digits[i] : 9;
                int64_t result = 0;
                for (int d = 0; d <= bound; ++d) {
                    result += memoization(i + 1, (i & 1) ? curr - d : curr + d, tight && d == bound);
                }
                if (!tight) {
                    memo[i][curr] = result;
                }
                return result;
            };
            
            return memoization(0, shift, true);
        };

        return count(high) - count(low - 1);
    }
};

// Time:  O((logn)^2)
// Space: O((logn)^2)
// memoization
class Solution3 {
public:
    long long countBalanced(long long low, long long high) {
        const auto& count = [&](int64_t n) {
            vector<int> digits;
            for (; n; n /= 10) {
                digits.emplace_back(n % 10);
            }
            ranges::reverse(digits);
            vector<vector<vector<int64_t>>> memo(size(digits), vector<vector<int64_t>>(size(digits) * 9 + 1, vector<int64_t>(2, -1)));
            const int shift = size(digits) / 2 * 9;
            const auto memoization = [&](this auto&& memoization, int i, int curr, bool tight) -> int64_t {
                if (i == size(digits)) {
                    return curr == shift;
                }
                if (memo[i][curr][tight] == -1) {
                    const auto& bound = tight ? digits[i] : 9;
                    int64_t result = 0;
                    for (int d = 0; d <= bound; ++d) {
                        result += memoization(i + 1, (i & 1) ? curr - d : curr + d, tight && d == bound);
                    }
                    memo[i][curr][tight] = result;
                }
                return memo[i][curr][tight];
            };
            
            return memoization(0, shift, true);
        };

        return count(high) - count(low - 1);
    }
};
