// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result;
        for (int i = 0; i < size(grid[0]); ++i) {
            int c = i;
            for (int r = 0; r < size(grid); ++r) {
                int nc = c + grid[r][c];
                if (!(0 <= nc && nc < size(grid[0]) && grid[r][nc] == grid[r][c])) {
                    c = -1;
                    break;
                }
                c = nc;
            }
            result.emplace_back(c);
        }
        return result;
    }
};
