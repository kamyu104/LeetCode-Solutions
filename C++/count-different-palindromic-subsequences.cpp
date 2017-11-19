// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        static const int P = 1e9 + 7;
        static const string chars = "abcd";
        vector<vector<vector<int>>> dp(3, vector<vector<int>>(S.size(), vector<int>(4)));
        for (int len = 1; len <= S.size(); ++len) {
            for (int i = 0; i + len <= S.size(); ++i) {
                for (const auto& c : chars) {
                    dp[len % 3][i][c - 'a'] = 0;
                    if (len == 1) {
                        dp[len % 3][i][c - 'a'] = S[i] == c;
                    } else {
                        if (S[i] != c) {
                            dp[len % 3][i][c - 'a'] = dp[(len - 1) % 3][i + 1][c - 'a'];
                        } else if (S[i + len - 1] != c) {
                            dp[len % 3][i][c - 'a'] = dp[(len - 1) % 3][i][c - 'a'];
                        } else {
                            dp[len % 3][i][c - 'a'] = 2;
                            if (len > 2) {
                                for (const auto& cc : chars) {
                                    dp[len % 3][i][c - 'a'] += dp[(len - 2) % 3][i + 1][cc - 'a'];
                                    dp[len % 3][i][c - 'a'] %= P;
                                }
                            }
                        }
                    }
                }
            }
        }
        int result = 0;
        for (const auto& c : chars) {
            result = (result + dp[S.size() % 3][0][c - 'a']) % P;
        }
        return result;
    }
};
