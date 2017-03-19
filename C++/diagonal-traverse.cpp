// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        
        vector<int> result;
        int row = 0, col = 0, d = 0;
        vector<vector<int>> dirs = {{-1, 1}, {1, -1}};
        
        for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
            result.emplace_back(matrix[row][col]);
            row += dirs[d][0];
            col += dirs[d][1];

            if (row >= static_cast<int>(matrix.size())) {
                row = matrix.size() - 1;
                col += 2;
                d = 1 - d;
            } else if (col >= static_cast<int>(matrix[0].size())) {
                col = matrix[0].size() - 1;
                row += 2;
                d = 1 - d;
            } else if (row < 0)  {
                row = 0;
                d = 1 - d;
            } else if (col < 0)  {
                col = 0;
                d = 1 - d;
            }
        }
        
        return result;
    }
};
