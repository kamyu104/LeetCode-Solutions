// Time Complexity: O((n!)^n)
// Space Complexiy: O(n^2)


class Solution {
    public:
        void solveSudoku(vector<vector<char> > &board) {
            solver(board);
        }
    private:
        bool solver(vector<vector<char> > &board) {
            for(int i = 0; i < 9; ++i) {
                for(int j = 0; j < 9; ++j) {
                    if(board[i][j] == '.') {
                        for(int k = 0; k < 9; ++k) {
                            board[i][j] = '1' + k;
                            if(isValid(board, i, j) && solver(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        bool isValid(vector<vector<char> > &board, int x, int y) {
            // row
            for(int i = 0; i < 9; ++i) {
                if(i != x && board[i][y] == board[x][y])
                    return false;
            }

            // column
            for(int j = 0; j < 9; ++j) {
                if(j != y && board[x][j] == board[x][y])
                    return false;
            }

            // block
            for(int i = 3 * (x / 3); i < 3 * (x / 3 + 1); ++i) {
                for(int j = 3 * (y / 3); j < 3 * (y / 3 + 1); ++j) {
                    if(!(i == x && j == y) && board[i][j] == board[x][y])
                        return false;
                }
            }

            return true;
        }
};
