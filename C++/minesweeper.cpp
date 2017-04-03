// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)  {
        queue<vector<int>> q;
        q.emplace(click);
        while (!q.empty()) {
            int row = q.front()[0], col = q.front()[1];
            q.pop();
            if (board[row][col] == 'M') {
                board[row][col] = 'X';
            } else {
                int count = 0;
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        if (i == 0 && j == 0) {
                            continue;
                        }
                        int r = row + i, c = col + j;
                        if (r < 0 || r >= board.size() || c < 0 || c < 0 || c >= board[r].size()) {
                            continue;
                        }
                        if (board[r][c] == 'M' || board[r][c] == 'X') {
                            ++count;
                        }
                    }
                }
                
                if (count > 0) {
                    board[row][col] = count + '0';
                } else {
                    board[row][col] = 'B';
                    for (int i = -1; i < 2; ++i) {
                        for (int j = -1; j < 2; ++j) {
                            if (i == 0 && j == 0) {
                                continue;
                            }
                            int r = row + i, c = col + j;
                            if (r < 0 || r >= board.size() || c < 0 || c < 0 || c >= board[r].size()) {
                                continue;
                            }
                            if (board[r][c] == 'E') {
                                vector<int> next_click = {r, c};
                                q.emplace(next_click);
                                board[r][c] = 'B';
                            }
                        }
                    }
                }
            }
        }
        
        return board;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)  {
        int row = click[0], col = click[1];
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            int count = 0;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int r = row + i, c = col + j;
                    if (r < 0 || r >= board.size() || c < 0 || c < 0 || c >= board[r].size()) {
                        continue;
                    }
                    if (board[r][c] == 'M' || board[r][c] == 'X') {
                        ++count;
                    }
                }
            }
            
            if (count > 0) {
                board[row][col] = count + '0';
            } else {
                board[row][col] = 'B';
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        if (i == 0 && j == 0) {
                            continue;
                        }
                        int r = row + i, c = col + j;
                        if (r < 0 || r >= board.size() || c < 0 || c < 0 || c >= board[r].size()) {
                            continue;
                        }
                        vector<int> next_click = {r, c};
                        if (board[r][c] == 'E') {
                            updateBoard(board, next_click);
                        }
                    }
                }
            }
        }
        
        return board;
    }
};
