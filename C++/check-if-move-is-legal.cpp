// Time:  O(8 * n) = O(1), grid is a n x n board and n = 8
// Space: O(1)

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        static const vector<pair<int, int>> directions = 
            {{0, -1}, {0, 1}, {-1, 0}, {1, 0},
             {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        for (const auto& [dr, dc] : directions) {
            int r = rMove + dr, c = cMove + dc;
            if (check(board, color, r, c, dr, dc)) {
                return true;
            }
        }
        return false;
    }

private:
    bool check(vector<vector<char>>& board, char color, int r, int c, int dr, int dc) {
        for (int l = 2;
             0 <= r && r < size(board) &&
             0 <= c && c < size(board[0]) &&
             board[r][c] != '.';
             r += dr, c += dc, ++l) {
            if (board[r][c] == color) {
                return l >= 3;
            }
        }
        return false;
    }
};
