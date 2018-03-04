// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        const auto FIRST = 'X', SECOND = 'O';
        const auto x_count =
            accumulate(board.cbegin(), board.cend(), 0,
                       [&FIRST](int accu, const string& s) {
                           return accu + count(s.cbegin(), s.cend(), FIRST);
                       });
        const auto o_count =
            accumulate(board.cbegin(), board.cend(), 0,
                       [&SECOND](int accu, const string& s) {
                           return accu + count(s.cbegin(), s.cend(), SECOND);
                       });
        if (o_count != x_count - 1 && o_count != x_count) {
            return false;
        }
        if (isWin(board, FIRST) && o_count != x_count - 1) {
            return false;
        }
        if (isWin(board, SECOND) && o_count != x_count) {
            return false;
        }
        return true;
    }

private:
    bool isWin(const vector<string>& board, char player) {
        for (int i = 0; i < board.size(); ++i) {
            if (all_of(board[i].cbegin(), board[i].cend(),
                       [&player](const char& c) {
                           return c == player;
                       })) {
                return true;
            }
            if (all_of(board.cbegin(), board.cend(),
                       [&i, &player](const string& row) {
                           return row[i] == player;
                       })) {
                return true;
            }
        }

        return (player == board[1][1] &&
                board[1][1] == board[0][0] &&
                board[0][0] == board[2][2]) ||
               (player == board[1][1] &&
                board[1][1] == board[0][2] &&
                board[0][2] == board[2][0]);
    }
};
