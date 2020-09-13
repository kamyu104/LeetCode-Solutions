// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(size(mat)), cols(size(mat[0]));
        for (int i = 0; i < size(rows); ++i) {
            for (int j = 0; j < size(cols); ++j) {
                if (mat[i][j]) {
                    ++rows[i], ++cols[j];
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(rows); ++i) {
            for (int j = 0; j < size(cols); ++j) {
                if (mat[i][j] && rows[i] == 1 && cols[j] == 1) {
                    ++result;
                }
            }
        }
        return result;
    }
};
