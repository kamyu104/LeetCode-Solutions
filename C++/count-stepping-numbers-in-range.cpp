// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        static const int MOD = 1e9 + 7;

        const auto& f = [](const auto& s) {
            vector<vector<int>> dp(2, vector<int>(10));
            for (int j = 1; j <= s[0] - '0'; ++j) {
                dp[0][j] = 1;
            }
            bool prefix = true;
            for (int i = 1; i < size(s); ++i) {
                for (int j = 0; j < 10; ++j) {
                    dp[i % 2][j] = static_cast<int>(j != 0);
                    if (j - 1 >= 0) {
                        dp[i % 2][j] = (dp[i % 2][j] + (((dp[(i - 1) % 2][j - 1] - static_cast<int>(prefix && (s[i - 1] - '0') == j - 1 && j > s[i] - '0' )) % MOD + MOD) % MOD)) % MOD;
                    }
                    if (j + 1 < 10) {
                        dp[i % 2][j] = (dp[i % 2][j] + (((dp[(i - 1) % 2][j + 1] - static_cast<int>(prefix && (s[i - 1] - '0') == j + 1 && j > s[i] - '0' )) % MOD + MOD) % MOD)) % MOD;
                    }
                }
                if (abs(s[i] - s[i - 1]) != 1) {
                    prefix = false;
                }
            }
            return accumulate(cbegin(dp[(size(s) - 1) % 2]), cend(dp[(size(s) - 1) % 2]), 0, [&](const auto& accu, const auto& x) {
                return (accu + x) % MOD;
            });
        };
    
        const auto& check = [](const auto& s) {
            for (int i = 0; i + 1 < size(s); ++i) {
                if (abs(s[i + 1] - s[i]) != 1) {
                    return false;
                }
            }
            return true;
        };
    
        return ((((f(high) - f(low)) % MOD + MOD) % MOD) + check(low)) % MOD;
    }
};
