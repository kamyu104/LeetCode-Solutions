// Time:  O((m * n) * log(m * n))
// Space: O(m * n)

// sort, greedy
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        vector<vector<int>> idxs;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                idxs.push_back({i, j});
            }
        }
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return grid[a[0]][a[1]] < grid[b[0]][b[1]];
        });
        vector<int> row_max(size(grid)), col_max(size(grid[0]));
        for (const auto& idx : idxs) {
            const int i = idx[0], j = idx[1];
            grid[i][j] = row_max[i] = col_max[j] = max(row_max[i], col_max[j]) + 1;
        }
        return grid;
    }
};
