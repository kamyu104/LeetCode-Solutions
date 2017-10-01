// Time:  O(k * n^2)
// Space: O(n^2)

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        static const vector<pair<int, int>> directions = 
            {{ 1, 2}, { 1, -2}, { 2, 1}, { 2, -1},
             {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
        vector<vector<vector<double>>> dp(2, vector<vector<double>>(N, vector<double>(N, 1.0l)));
        for (int step = 1; step <= K; ++step) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dp[step % 2][i][j] = 0;
                    for (const auto& direction : directions) {
                        auto rr = i + direction.first;
                        auto cc = j + direction.second;
                        if (0 <= cc && cc < N && 0 <= rr && rr < N) {
                            dp[step % 2][i][j] += 0.125l * dp[(step - 1) % 2][rr][cc];
                        }
                    }
                }
            }
        }
        return dp[K % 2][r][c];
    }
};
