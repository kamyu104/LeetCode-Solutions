// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> row(2, vector<int>(3));
        vector<vector<int>> col(2, vector<int>(3));
        vector<int> diag(2), anti_diag(2);
        int p = 0;
        for (const auto& move : moves) {
            int r = move[0], c = move[1];
            ++row[p][r];
            ++col[p][c];
            diag[p] += (r == c);
            anti_diag[p] += (r + c == 2);
            vector<int> tmp = {row[p][r], col[p][c], diag[p], anti_diag[p]};
            if (find(tmp.cbegin(), tmp.cend(), 3) != tmp.cend()) {
                return string(1, "AB"[p]);
            }
            p ^= 1;
        }
        return  moves.size() == 9 ? "Draw" : "Pending";
    }
};
