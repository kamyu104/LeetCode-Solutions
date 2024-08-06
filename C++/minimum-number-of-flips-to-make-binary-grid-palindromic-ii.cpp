// Time:  O(m * n)
// Space: O(1)

// array, greedy
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        const int m = size(grid), n = size(grid[0]);
        int result = 0;
        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                const int c = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                result += min(c, 4 - c);
            }
        }
        int diff = 0, cnt1 = 0;
        if (m % 2) {
            for (int j = 0; j < n / 2; ++j) {
                diff += grid[m / 2][j] ^ grid[m / 2][n - 1 - j];
                cnt1 += grid[m / 2][j] + grid[m / 2][n - 1 - j];
            }
        }
        if (n % 2) {
            for (int i = 0; i < m / 2; ++i) {
                diff += grid[i][n / 2] ^ grid[m - 1 - i][n / 2];
                cnt1 += grid[i][n / 2] + grid[m - 1 - i][n / 2];
            }
        }
        if (m % 2 && n % 2) {
            result += grid[m / 2][n / 2];
        }
        if (diff == 0) {
            result += (4 - cnt1 % 4) % 4;
        }
        return result + diff;
    }
};
