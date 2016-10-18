// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return 0;
        }

        int cnt = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                cnt += board[i][j] == 'X' &&
                       (i == 0 || board[i - 1][j] != 'X') &&
                       (j == 0 || board[i][j - 1] != 'X');
            }
        }
        return cnt;
    }
};
