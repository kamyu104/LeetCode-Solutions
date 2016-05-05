// Time:  O(1), per move.
// Space: O(n^2)

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : rows_(n, {0, 0}), cols_(n, {0, 0}),
                       diagonal_(2, 0), anti_diagonal_(2, 0) {
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        const int i = player - 1;
        ++rows_[row][i], ++cols_[col][i];
        if (row == col) {
            ++diagonal_[i];
        }
        if (col == rows_.size() - row - 1) {
            ++anti_diagonal_[i];
        }
        if (rows_[row][i] == rows_.size() ||
            cols_[col][i] == cols_.size() ||
            diagonal_[i] == rows_.size() ||
            anti_diagonal_[i] == cols_.size()) {
            return player;
        }
        return 0;
    }

private:
    vector<vector<int>> rows_, cols_;
    vector<int> diagonal_, anti_diagonal_;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
