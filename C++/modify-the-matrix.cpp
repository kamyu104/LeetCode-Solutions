// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int j = 0; j < size(matrix[0]); ++j) {
            int mx = -1;
            for (int i = 0; i < size(matrix); ++i) {
                mx = max(mx, matrix[i][j]);
            }
            for (int i = 0; i < size(matrix); ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
};
