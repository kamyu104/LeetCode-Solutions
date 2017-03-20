// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> queue;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    queue.emplace(i, j);
                }
                else {
                    matrix[i][j] = numeric_limits<int>::max();
                }
            }
        }

        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!queue.empty()) {
            auto cell = queue.front();
            queue.pop();
            for (const auto& dir : dirs) {
                auto i = cell.first + dir.first;
                auto j = cell.second + dir.second;
                if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || 
                    matrix[i][j] <= matrix[cell.first][cell.second] + 1) {
                        continue;
                }
                queue.emplace(i, j);
                matrix[i][j] = matrix[cell.first][cell.second] + 1;
            }
        }
        
        return matrix;
    }
};
