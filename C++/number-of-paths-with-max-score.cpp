// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        static const int MOD = 1e9 + 7;
        static const vector<pair<int, int>> directions{{1, 0}, {0, 1}, {1, 1}};
        
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(board[0].size() + 1, vector<int>(2)));
        dp[(board.size() - 1) % 2][board[0].size() - 1] = {0, 1};
        for (int r = board.size() - 1; r >= 0; --r) {
            for (int c = board[0].size() - 1; c >= 0; --c) {
                if (board[r][c] == 'S' || board[r][c] == 'X') {
                    continue;
                }
                dp[r % 2][c] = {0, 0};
                for (const auto& [dr, dc] : directions) {
                    if (dp[r % 2][c][0] < dp[(r + dr) % 2][c + dc][0]) {
                        dp[r % 2][c] = dp[(r + dr) % 2][c + dc];
                    } else if (dp[r % 2][c][0] == dp[(r + dr) % 2][c + dc][0]) {
                        dp[r % 2][c][1] = (dp[r % 2][c][1]+dp[(r + dr) % 2][c + dc][1]) % MOD;
                    }
                }
                if (dp[r % 2][c][1] && board[r][c] != 'E') {
                    dp[r % 2][c][0] += board[r][c] - '0';
                }
            }
        }
        return dp[0][0];
    }
};
