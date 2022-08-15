// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const auto& find_max = [&](int i, int j) {
            int result = 0;
            for (int ni = i; ni < i + 3; ++ni) {
                for (int nj = j; nj < j + 3; ++nj) {
                    result = max(result, grid[ni][nj]);
                }
            }
            return result;
        };

        vector<vector<int>> result(size(grid) - 2, vector<int>(size(grid[0]) - 2));
        for (int i = 0; i < size(grid) - 2; ++i) {
            for (int j = 0; j < size(grid[0]) - 2; ++j) {
                result[i][j] = find_max(i, j);
            }
        }
        return result;
    }
};
