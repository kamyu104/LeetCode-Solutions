// Time:  O(n * m)
// Space: O(1)

// kadane's algorithm
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        const auto& modified_kadane = [](int l, const auto& get) {
            int curr = get(0) + get(1);
            int result = curr;
            for (int i = 2; i < l; ++i) {
                curr = max(curr, get(i - 1)) + get(i);
                result = max(result, curr);
            }
            return result;
        };

        int result = numeric_limits<int>::min();
        for (int i = 0; i < size(grid); ++i) {
            result = max(result, modified_kadane(size(grid[0]), [&](int j) {
                return grid[i][j];
            }));
        }
        for (int j = 0; j < size(grid[0]); ++j) {
            result = max(result, modified_kadane(size(grid), [&](int i) {
                return grid[i][j];
            }));
        }
        for (int i = 1; i + 1 < size(grid); ++i) {
            for (int j = 1; j + 1 < size(grid[0]); ++j) {
                result = max(result, grid[i][j]);
            }
        }
        return result;
    }
};
