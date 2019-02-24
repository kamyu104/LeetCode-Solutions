// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        static vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int r = -1, c = -1;
        for (int i = 0; i < 8 && r == -1; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    tie(r, c) = make_pair(i, j);
                    break;
                }
            }
        }

        int result = 0;
        for (const auto& d : directions) {
            int nr, nc;
            tie(nr, nc) = make_pair(r + d.first, c + d.second);
            while (0 <= nr && nr < 8 && 0 <= nc && nc < 8) {
                if (board[nr][nc] == 'p') {
                    ++result;
                }
                if (board[nr][nc] != '.') {
                    break;
                }
                tie(nr, nc) = make_pair(nr + d.first, nc + d.second);
            }
        }
        return result;
    }
};
