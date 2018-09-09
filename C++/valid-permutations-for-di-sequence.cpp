// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int numPermsDISequence(string S) {
        const int M = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(S.length() + 1, 1));
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == 'I') {
                dp[(i + 1) % 2][0] = dp[i % 2][0];
                for (int j = 1; j < S.length() - i; ++j) {
                    dp[(i + 1) % 2][j] = (dp[(i + 1) % 2][j - 1] + dp[i % 2][j]) % M;
                }
            } else {
                dp[(i + 1) % 2][S.length() - i - 1] = dp[i % 2][S.length() - i];
                for (int j = S.length() - i - 2; j >= 0; --j) {
                    dp[(i + 1) % 2][j] = (dp[(i + 1) % 2][j + 1] + dp[i % 2][j + 1]) % M;
                }
            }
        }
        return dp[S.length() % 2][0];
    }
};
