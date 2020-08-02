// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int result = 0;
        for (int target = grid.size() - 1; target >= 1; --target) {
            int row_idx = grid.size() - 1 - target;
            for (; row_idx < grid.size(); ++row_idx) {
                const auto& row = grid[row_idx];
                if (!accumulate(crbegin(row), crbegin(row) + target, 0)) {
                    break;
                }
            }
            if (row_idx == grid.size()) {
                return -1;
            }
            for (; row_idx != grid.size() - 1 - target; --row_idx) {
                swap(grid[row_idx], grid[row_idx-1]);
                ++result;
            }
        }
        return result;
    }
};
