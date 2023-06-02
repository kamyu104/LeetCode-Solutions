// Time:  O(m * n)
// Space: O(min(m, n))

// prefix sum
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> result(size(grid), vector<int>(size(grid[0])));
        const auto& update = [&](int i, int j) {
            unordered_set<int> lookup;
            for (int k = 0; k < min(size(grid) - i, size(grid[0]) - j); ++k) {
                result[i + k][j + k] = size(lookup);
                lookup.emplace(grid[i + k][j + k]);
            }
            lookup.clear();
            for (int k = min(size(grid) - i, size(grid[0]) - j) - 1; k >= 0; --k) {
                result[i + k][j + k] = abs(result[i + k][j + k] - static_cast<int>(size(lookup)));
                lookup.emplace(grid[i + k][j + k]);
            }
        };

        for (int j = 0; j < size(grid[0]); ++j) {
            update(0, j);
        }
        for (int i = 1; i < size(grid); ++i) {
            update(i, 0);
        }
        return result;
    }
};
