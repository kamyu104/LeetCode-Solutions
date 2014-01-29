// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            bool used[9];

            for(int i = 0; i < 9; ++i) {
                fill(used, used + 9, false);
                for(int j = 0; j < 9; ++j) {
                    if(!check(board[i][j], used))
                        return false;
                }

                fill(used, used + 9, false);
                for(int j = 0; j < 9; ++j) {
                    if(!check(board[j][i], used))
                        return false;
                }
            }

            for(int r = 0; r < 3; ++r) {
                for(int c = 0; c < 3; ++c) {
                    fill(used, used + 9, false);
                    for(int i = 3 * r;  i < 3 * (r + 1); ++i) {
                        for(int j = 3 * c;  j < 3 * (c + 1); ++j) {
                            if(!check(board[i][j], used))
                                return false;
                        }
                    }
                }
            }

            return true;
        }

    private:
        bool check(char c, bool used[9]) {
            if(c != '.') {
                if(used[c - '1'])
                    return false;
                used[c - '1'] = true;
            }
            return true;
        }
};
