// Time:  O(m * n)
// Space: O(m + n)

// dfs
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)  {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        vector<pair<int, int>> stk;
        stk.emplace_back(click[0], click[1]);
        while (!empty(stk)) {
            const auto [r, c] = stk.back(); stk.pop_back();
            int cnt = 0;
            vector<pair<int, int>> adj;
            for (int dr = -1; dr < 2; ++dr) {
                for (int dc = -1; dc < 2; ++dc) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }
                    const int nr = r + dr, nc = c + dc;
                    if (!(0 <= nr && nr < size(board) && 0 <= nc && nc < size(board[0]))) {
                        continue;
                    }
                    if (board[nr][nc] == 'M') {
                        ++cnt;
                    } else if (board[nr][nc] == 'E') {
                        adj.emplace_back(nr, nc);
                    }
                }
            }
            if (cnt) {
                board[r][c] = cnt + '0';
                continue;
            }
            board[r][c] = 'B';
            for (const auto& [nr, nc] : adj) {
                board[nr][nc] = ' ';
                stk.emplace_back(nr, nc);
            }
        }
        return board;
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// bfs
class Solution2 {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)  {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        vector<pair<int, int>> q;
        q.emplace_back(click[0], click[1]);
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [r, c] : q) {
                int cnt = 0;
                vector<pair<int, int>> adj;
                for (int dr = -1; dr < 2; ++dr) {
                    for (int dc = -1; dc < 2; ++dc) {
                        if (dr == 0 && dc == 0) {
                            continue;
                        }
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < size(board) && 0 <= nc && nc < size(board[0]))) {
                            continue;
                        }
                        if (board[nr][nc] == 'M') {
                            ++cnt;
                        } else if (board[nr][nc] == 'E') {
                            adj.emplace_back(nr, nc);
                        }
                    }
                }
                if (cnt) {
                    board[r][c] = cnt + '0';
                    continue;
                }
                board[r][c] = 'B';
                for (const auto& [nr, nc] : adj) {
                    board[nr][nc] = ' ';
                    new_q.emplace_back(nr, nc);
                }
            }
            q = move(new_q);
        }
        return board;
    }
};
