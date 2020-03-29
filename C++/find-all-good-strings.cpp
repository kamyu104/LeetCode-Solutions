// Time:  O(m * n)
// Space: O(m)

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        const auto& prefix = getPrefix(evil);
        vector<vector<vector<vector<int>>>> dp(
            2, vector<vector<vector<int>>>(
                   2, vector<vector<int>>(
                          2, vector<int>(evil.length()))));
        dp[0][0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
            dp[(i + 1) % 2] = vector<vector<vector<int>>>(
                                  2, vector<vector<int>>(
                                      2, vector<int>(evil.length())));
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    const auto min_c = j ? 'a' : s1[i];
                    const auto max_c = k ? 'z' : s2[i];
                    for (int l = 0; l < evil.length(); ++l) {
                        if (!dp[i % 2][j][k][l]) {
                            continue;
                        }
                        for (char c = min_c; c <= max_c; ++c) {
                            int m = l - 1;
                            while (m != -1 && evil[m + 1] != c) {
                                m = prefix[m];
                            }
                            if (evil[m + 1] == c) {
                                ++m;
                            }
                            if (m + 1 == evil.length()) {
                                continue;
                            }
                            add(&dp[(i + 1) % 2][j || c != s1[i]][k || c != s2[i]][m + 1], dp[i % 2][j][k][l]);
                        }
                    }
                }
            }
        }
        int result = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < evil.length(); ++l) {
                    add(&result, dp[n % 2][j][k][l]);
                }
            }
        }
        return result;
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j != -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
    
    void add(int *x, int y) {
        static const int MOD = 1e9 + 7;
        *x = (*x + y) % MOD;
    }
};
