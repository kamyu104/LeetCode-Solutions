// Time:  O(n * m)
// Space: O(n * m)

// dp
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int result = 0;
        vector<vector<int>> dp1(size(grid) + 1, vector<int>(size(grid[0]) + 1));
        vector<vector<int>> dp2(size(grid) + 1, vector<int>(size(grid[0]) + 1));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                dp1[i + 1][j + 1] = dp1[i][j + 1] + dp1[i + 1][j] - dp1[i][j] + (grid[i][j] == 'X' ? 1 : 0);
                dp2[i + 1][j + 1] = dp2[i][j + 1] + dp2[i + 1][j] - dp2[i][j] + (grid[i][j] == 'Y' ? 1 : 0);
                if (dp1[i + 1][j + 1] == dp2[i + 1][j + 1] && dp2[i + 1][j + 1] != 0) {
                    ++result;
                }
            }
        }
        return result;
    }
};

// Time:  O(n * m)
// Space: O(n * m)
// dp
class Solution2 {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int result = 0;
        vector<vector<int>> dp1(size(grid), vector<int>(size(grid[0])));
        vector<vector<int>> dp2(size(grid), vector<int>(size(grid[0])));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (i - 1 >= 0) {
                    dp1[i][j] += dp1[i - 1][j];
                    dp2[i][j] += dp2[i - 1][j];
                }
                if (j - 1 >= 0) {
                    dp1[i][j] += dp1[i][j - 1];
                    dp2[i][j] += dp2[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp1[i][j] -= dp1[i - 1][j - 1];
                    dp2[i][j] -= dp2[i - 1][j - 1];
                }
                dp1[i][j] += (grid[i][j] == 'X' ? 1 : 0);
                dp2[i][j] += (grid[i][j] == 'Y' ? 1 : 0);
                if (dp1[i][j] == dp2[i][j] && dp2[i][j] != 0) {
                    ++result;
                }
            }
        }
        return result;
    }
};
