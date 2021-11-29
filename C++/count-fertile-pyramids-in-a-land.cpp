// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        return count(grid, false) + count(grid, true);
    }

private:
    int count(const vector<vector<int>>& grid, int reverse) {
        auto get_grid = [&grid, &reverse](int i, int j) {
            return reverse ? grid[size(grid) - 1 - i][j] : grid[i][j];
        };

        int result = 0;
        vector<int> dp(size(grid[0]));
        for (int i = 1; i < size(grid); ++i) {
            vector<int> new_dp(size(grid[0]));
            for (int j = 1; j + 1 < size(grid[0]); ++j) {
                if (get_grid(i, j) == get_grid(i - 1, j - 1) &&
                    get_grid(i - 1, j - 1) == get_grid(i - 1, j) &&
                    get_grid(i - 1, j) == get_grid(i - 1, j + 1) &&
                    get_grid(i - 1, j + 1) == 1) {
                    new_dp[j] = min(dp[j - 1], dp[j + 1]) + 1;
                }
            }
            dp = move(new_dp);
            result += accumulate(cbegin(dp), cend(dp), 0);
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    int countPyramids(vector<vector<int>>& grid) {
        return count(grid) + count(vector<vector<int>>(rbegin(grid), rend(grid)));
    }

private:
    int count(const vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<int>> dp(size(grid), vector<int>(size(grid[0])));
        for (int i = 1; i < size(grid); ++i) {
            for (int j = 1; j + 1 < size(grid[0]); ++j) {
                if (grid[i][j] == grid[i - 1][j - 1] &&
                    grid[i - 1][j - 1] == grid[i - 1][j] &&
                    grid[i - 1][j] == grid[i - 1][j + 1] &&
                    grid[i - 1][j + 1] == 1) {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + 1;
                }
            }
            result += accumulate(cbegin(dp[i]), cend(dp[i]), 0);
        }
        return result;
    }
};
