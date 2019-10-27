// Time:  O(n^2 * m^2 * m^(n * m)), given m < n
// Space: O(n * m)

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (m > n) {
            return tilingRectangle(m, n);
        }
        vector<vector<int>> board(n, vector<int>(m));
        int result = numeric_limits<int>::max();
        backtracking(&board, 0, &result);
        return result;
    }

private:
    pair<int, int> find_next(const vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!board[i][j]) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    int find_max_length(const vector<vector<int>>& board, int i, int j) {
        int max_length = 1;
        while (i + max_length - 1 < board.size() &&
               j + max_length - 1 < board[0].size()) {
            for (int r = i; r < i + max_length - 1; ++r) {
                if (board[r][j + max_length - 1]) {
                    return max_length - 1;
                }
            }
            for (int c = j; c < j + max_length; ++c) {
                if (board[i + max_length - 1][c]) {
                    return max_length - 1;
                }
            }
            ++max_length;
        }
        return max_length - 1;
    }

    void fill(vector<vector<int>> *board,
              int i, int j, int length, int val) {
        for (int r = i; r < i + length; ++r) {
            for (int c = j; c < j + length; ++c) {
                (*board)[r][c] = val;
            }
        }
    }

    void backtracking(vector<vector<int>> *board,
                      int count, int *result) {
        if (count >= *result) { // pruning
            return;
        }
        const auto& [i, j] = find_next(*board);
        if (i == -1 && j == -1) {  // finished
            *result = min(*result, count);
            return;
        }
        const auto& max_length = find_max_length(*board, i, j);
        for (int k = max_length; k >= 1; --k) {
            fill(board, i, j, k, 1);
            backtracking(board, count + 1, result);
            fill(board, i, j, k, 0);
        }
    }
};
