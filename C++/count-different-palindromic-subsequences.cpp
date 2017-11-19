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

// Time:  O(n^2)
// Space: O(n^2)
class Solution2 {
public:
    int countPalindromicSubsequences(string S) {
        vector<vector<int>> prv(S.length(), vector<int>(4, -1));
        vector<vector<int>> nxt(S.length(), vector<int>(4, -1));
        vector<int> last(4, -1);
        for (int i = 0; i < S.length(); ++i) {
            last[S[i] - 'a'] = i;
            prv[i] = last;
        } 
        last = vector<int>(4, -1);
        for (int i = S.length() - 1; i >= 0; --i) {
            last[S[i] - 'a'] = i;
            nxt[i] = last;
        }
        vector<vector<int>> lookup(S.length(), vector<int>(S.length(), -1));
        return dp(0, S.length() - 1, prv, nxt, &lookup) - 1;
    }

private:
    int dp(const int i, const int j,
           const vector<vector<int>>& prv,
           const vector<vector<int>>& nxt,
           vector<vector<int>> *lookup) {
        
        if ((*lookup)[i][j] != -1) {
            return (*lookup)[i][j];
        }
        auto result = 1;
        if (i <= j) {
            for (int x = 0; x < 4; ++x) {
                auto i0 = nxt[i][x];
                auto j0 = prv[j][x];
                if (i <= i0 && i0 <= j) {
                    result = (result + 1) % P;
                }
                if (i0 != -1 && j0 != -1 && i0 < j0) {
                    result = (result + dp(i0 + 1, j0 - 1, prv, nxt, lookup)) % P;
                }
            }
        }
        result %= P;
        (*lookup)[i][j] = result;
        return result;
    }
    static const int P = 1e9 + 7;
};
