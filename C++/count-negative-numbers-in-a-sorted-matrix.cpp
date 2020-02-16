// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0, c = grid[0].size() - 1;
        for (const auto& row : grid) {
            while (c >= 0 && row[c] < 0) {
                --c;
            }
            result += grid[0].size() - 1 - c;
        }
        return result;
    }
};
