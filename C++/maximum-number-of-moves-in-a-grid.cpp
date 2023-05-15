// Time:  O(m * n)
// Space: O(m)

// dp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<int> dp(size(grid));
        for (int c = size(grid[0]) - 2; c >= 0; --c) {
            vector<int> new_dp(size(grid));
            for (int r = 0; r < size(grid); ++r) {
                if (grid[r][c] < grid[r][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r] + 1);
                }
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r - 1] + 1);
                }
                if (r + 1 < size(grid) && grid[r][c] < grid[r + 1][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r + 1] + 1);
                }
            }
            dp = move(new_dp);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};
