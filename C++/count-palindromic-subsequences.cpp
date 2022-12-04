// Time:  O(10^(l/2) * n), l = 5
// Space: O(10^(l/2) * n)

// freq table, prefix sum
class Solution {
public:
    int countPalindromes(string s) {
        static const int MOD = 1e9 + 7;
        vector<int> cnt(10);
        vector<vector<vector<int64_t>>> left(size(s) + 1, vector<vector<int64_t>>(10, vector<int64_t>(10)));
        for (int k = 0; k < size(s); ++k) {
            left[k + 1] = left[k];
            for (int i = 0; i < 10; ++i) {
                left[k + 1][s[k] - '0'][i] += cnt[i];
            }
            ++cnt[s[k] - '0'];
        }
        cnt.assign(10, 0);
        vector<vector<int64_t>> right(10, vector<int64_t>(10));
        int result = 0;
        for (int k = size(s) - 1; k >= 0; --k) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    result = (result + left[k][i][j] * right[i][j]) % MOD;
                }
            }
            for (int i = 0; i < 10; ++i) {
                right[s[k] - '0'][i] += cnt[i];
            }
             ++cnt[s[k] - '0'];
        }
        return result;
    }
};

// Time:  O(10^(l/2) * n * l), l = 5
// Space: O(l)
// dp
class Solution2 {
public:
    int countPalindromes(string s) {
        static const int MOD = 1e9 + 7;
        int result = 0;
        for (char i = '0'; i <= '9'; ++i) {
            for (char j = '0'; j <= '9'; ++j) {
                const string pattern = {i, j, '*', j, i};
                vector<int> dp(5 + 1);
                dp[0] = 1;
                for (int k = 0; k < size(s); ++k) {
                    for (int l = 4; l >= 0; --l) {
                        if (pattern[l] == '*' || pattern[l] == s[k]) {
                            dp[l + 1] = (dp[l + 1] + dp[l]) % MOD;
                        }
                    }
                }
                result = (result + dp[5]) % MOD;
            }
        }
        return result;
    }
};
