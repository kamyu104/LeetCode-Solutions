// Time:  O(N * m * n)
// Space: O(m * n)

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        const auto M = 1000000000 + 7;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n)));
        for (int moves = 0; moves < N; ++moves) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[(moves + 1) % 2][i][j] = (((i == 0 ? 1 : dp[moves % 2][i - 1][j]) +
                                                  (i == m - 1 ? 1 : dp[moves % 2][i + 1][j])) % M +
                                                 ((j == 0 ? 1 : dp[moves % 2][i][j - 1]) +
                                                  (j == n - 1 ? 1 : dp[moves % 2][i][j + 1])) % M) % M;
                }
            }
        }
        return dp[N % 2][i][j];
    }
};
