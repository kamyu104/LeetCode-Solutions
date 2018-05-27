// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i + k - 1 < grid.size(); ++i) {
            for (int j = 0; j + k - 1 < grid[j].size(); ++j) {
                if (magic(grid, i, j)) {
                    ++result;
                }
            }
        }
        return result;
    }

private:
    static const int k = 3;

    bool magic(const vector<vector<int>>& grid, int r, int c) {
        const int expect = k * (k * k + 1) / 2; 
        unordered_set<int> nums;
        int min_num = numeric_limits<int>::max();
        int sum_diag = 0, sum_anti = 0;
        for (int i = 0; i < k; ++i) {
            sum_diag += grid[r + i][c + i];
            sum_anti += grid[r + i][c + k - 1 - i];
            int sum_r = 0, sum_c = 0;
            for (int j = 0; j < k; ++j) {
                min_num = min(min_num, grid[r + i][c + j]);
                nums.emplace(grid[r + i][c + j]);
                sum_r += grid[r + i][c + j];
                sum_c += grid[r + j][c + i];
            }
            if (!(sum_r == sum_c &&
                  sum_c == expect)) {
                return false;
            }
        }
        return sum_diag == sum_anti &&
               sum_anti == expect &&
               nums.size() == k * k &&
               min_num == 1;
    }
};
