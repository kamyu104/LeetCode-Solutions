// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        queue<pair<int, int>> q;
        for (int i = 0; i < board.size(); ++i) {
            q.emplace(i, 0);
            q.emplace(i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            q.emplace(0, j);
            q.emplace(board.size() - 1, j);
        }

        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            if (board[i][j] == 'O' || board[i][j] == 'V') {
                board[i][j] = 'V';
                const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                        {-1, 0}, {1, 0}};
                for (const auto& d : directions) {
                    const int x = i + d.first, y = j + d.second;
                    if (0 <= x  && x < board.size() &&
                        0 <= y && y < board[0].size() &&
                        board[x][y] == 'O') {
                        board[x][y] = 'V';
                        q.emplace(x, y);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != 'V') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
