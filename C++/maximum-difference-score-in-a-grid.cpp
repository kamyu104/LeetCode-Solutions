// Time:  O(m * n)
// Space: O(1)

// dp
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        static const int POS_INF= numeric_limits<int>::max();
        static const int NEG_INF = numeric_limits<int>::min();

        int result = NEG_INF;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                int mn = POS_INF;
                if (i - 1 >= 0) {
                    mn = min(mn, grid[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    mn = min(mn, grid[i][j - 1]);
                }
                if (mn != POS_INF) {
                    result = max(result, grid[i][j] - mn);
                    grid[i][j] = min(grid[i][j], mn);
                }
            }
        }
        return result;
    }
};
