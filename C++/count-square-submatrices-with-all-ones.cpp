// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) {
                    continue;
                }
                int l = min(matrix[i - 1][j], matrix[i][j - 1]);
                matrix[i][j] = matrix[i - l][j - l] ? l + 1 : l;
            }
        }
        int result = 0;
        for (const auto& row : matrix) {
            for (const auto& x : row) {
                result += x;
            }
        }
        return result;
    }
};
