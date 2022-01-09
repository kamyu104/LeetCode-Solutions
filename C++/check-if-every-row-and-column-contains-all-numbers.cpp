// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for (int i = 0; i < size(matrix); ++i) {
            int r = 0, c = 0;
            for (int j = 0; j < size(matrix[0]); ++j) {
                r ^= matrix[i][j] ^ (j + 1);
                c ^= matrix[j][i] ^ (j + 1);
            }
            if (r || c) {
                return false;
            }
        }
        return true;
    }
};
