// Time:  O(n^2 * logn)
// Space: O(n^2)

// sort
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> lookup(((size(grid) - 1) + (size(grid[0]) - 1)) - (0 - (size(grid[0]) - 1)) + 1);
        const int shift = size(grid[0]) - 1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup[(i - j) + shift].emplace_back(grid[i][j]);
            }
        }
        for (int i = 0; i < size(lookup); ++i) {
            if (i - shift < 0) {
                sort(begin(lookup[i]), end(lookup[i]), greater<int>());
            } else {
                sort(begin(lookup[i]), end(lookup[i]));
            }
        }
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                grid[i][j] = lookup[(i - j) + shift].back(); lookup[(i - j) + shift].pop_back();
            }
        }
        return grid;
    }
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// sort
class Solution2 {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> lookup(((size(grid) - 1) + (size(grid[0]) - 1)) - (0 - (size(grid[0]) - 1)) + 1);
        const int shift = size(grid[0]) - 1;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup[((i - j) + size(lookup)) % size(lookup)].emplace_back(grid[i][j]);
            }
        }
        for (int i = 0 - static_cast<int>(size(grid[0]) - 1); i <= static_cast<int>((size(grid) - 1) + (size(grid[0]) - 1)); ++i) {
            if (i < 0) {
                sort(begin(lookup[(i + size(lookup)) % size(lookup)]), end(lookup[(i + size(lookup)) % size(lookup)]), greater<int>());
            } else {
                sort(begin(lookup[(i + size(lookup)) % size(lookup)]), end(lookup[(i + size(lookup)) % size(lookup)]));
            }
        }
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                grid[i][j] = lookup[((i - j) + size(lookup)) % size(lookup)].back(); lookup[((i - j) + size(lookup)) % size(lookup)].pop_back();
            }
        }
        return grid;
    }
};
