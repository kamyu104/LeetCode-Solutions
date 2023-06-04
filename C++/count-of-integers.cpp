// Time:  O(n * m), m = max_sum
// Space: O(m)

// combinatorics, dp
class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        static const int MOD = 1e9 + 7;
        const auto& check = [&](const auto& x) {
            const auto& total = accumulate(cbegin(x), cend(x), 0, [](const auto& accu, const auto& c) {
                return accu + (c - '0');
            });
            return min_sum <= total && total <= max_sum;
        };

        const auto& f = [&](const auto& x) {
            vector<vector<int>> dp(2, vector<int>(max_sum + 1));
            dp[0][0] = dp[1][0] = 1;
            for (int i = size(x) - 1; i >= 0; --i) {
                vector<vector<int>> new_dp(2, vector<int>(max_sum + 1));
                for (int t = 0; t < 2; ++t) {
                    for (int total = 0; total <= max_sum; ++total) {
                        for (int d = 0; d <= min((t == 1 ? x[i] - '0' : 9), total); ++d) {
                            new_dp[t][total] = (new_dp[t][total] + dp[static_cast<int>(t && d == x[i] - '0')][total - d]) % MOD;
                        }
                    }
                }
                dp = move(new_dp);
            }
            int result = 0;
            for (int total = min_sum; total <= max_sum; ++total) {
                result = (result + dp[1][total]) % MOD;
            }
            return result;
        };

        return (((f(num2) - f(num1)) % MOD + MOD) % MOD + check(num1)) % MOD;
    }
};

// Time:  O(n * m), m = max_sum
// Space: O(m)
// combinatorics, dp
class Solution2 {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        static const int MOD = 1e9 + 7;
        const auto& dec = [](auto& x) {
            for (int i = size(x) - 1; i >= 0; --i) {
                if (x[i] != '0') {
                    --x[i];
                    break;
                }
                x[i] = '9';
            }
            return x;
        };

        const auto& f = [&](const auto& x) {
            vector<vector<int>> dp(2, vector<int>(max_sum + 1));
            dp[0][0] = dp[1][0] = 1;
            for (int i = size(x) - 1; i >= 0; --i) {
                vector<vector<int>> new_dp(2, vector<int>(max_sum + 1));
                for (int t = 0; t < 2; ++t) {
                    for (int total = 0; total <= max_sum; ++total) {
                        for (int d = 0; d <= min((t == 1 ? x[i] - '0' : 9), total); ++d) {
                            new_dp[t][total] = (new_dp[t][total] + dp[static_cast<int>(t && d == x[i] - '0')][total - d]) % MOD;
                        }
                    }
                }
                dp = move(new_dp);
            }
            int result = 0;
            for (int total = min_sum; total <= max_sum; ++total) {
                result = (result + dp[1][total]) % MOD;
            }
            return result;
        };

        return ((f(num2) - f(dec(num1)) % MOD) + MOD) % MOD;
    }
};
