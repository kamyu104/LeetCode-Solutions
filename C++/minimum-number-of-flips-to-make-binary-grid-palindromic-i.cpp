// Time:  O(m * n)
// Space: O(1)

// array, greedy
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const auto& count = [](int m, int n, const auto& get) {
            int result = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n / 2; ++j) {
                    if (get(i, j) != get(i, n - 1 - j)) {
                        ++result;
                    }
                }
            }
            return result;
        };

        return min(count(size(grid), size(grid[0]), [&](int i, int j) { return grid[i][j]; }),
                   count(size(grid[0]), size(grid), [&](int i, int j) { return grid[j][i]; }));
    }
};
