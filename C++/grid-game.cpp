// Time:  O(n)
// Space: O(1)

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int64_t result = numeric_limits<int64_t>::max();
        int64_t left = 0, right = accumulate(cbegin(grid[0]), cend(grid[0]), 0ll);
        for (int i = 0; i < size(grid[0]); ++i) {
            right -= grid[0][i];
            result = min(result, max(left, right));
            left += grid[1][i];
        }
        return result;
    }
};
