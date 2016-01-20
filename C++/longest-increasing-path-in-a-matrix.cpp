// Time:  O(m * n)
// Space: O(m * n)

// DFS + Memorization solution.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int res = 0;
        vector<vector<int>> states(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
             res = max(res, longestpath(matrix, i, j, &states));
            }
        }
    
        return res;
    }

private:
    int longestpath(const vector<vector<int>>& matrix, const int i, const int j,
                    vector<vector<int>> *states) {
        if ((*states)[i][j] > 0) {
            return (*states)[i][j];
        }
    
        int max_depth = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            const int x = i + d.first, y = j + d.second;
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[x][y] < matrix[i][j]) {
                max_depth = max(max_depth,
                                longestpath(matrix, x, y, states));
            }
        }
        (*states)[i][j] = max_depth + 1;
        return (*states)[i][j];
    }
};
