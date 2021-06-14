// Time:  O(max(m, n) * min(m, n)^3)
// Space: O(m + n)

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> prefix_row(size(grid), vector<int>(size(grid[0]) + 1));
        vector<vector<int>> prefix_col(size(grid[0]), vector<int>(size(grid) + 1));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                prefix_row[i][j + 1] = prefix_row[i][j] + grid[i][j];
                prefix_col[j][i + 1] = prefix_col[j][i] + grid[i][j];
            }
        }
        for (int l = min(size(grid), size(grid[0])); l >= 1; --l) {
            for (int i = 0; i + l - 1 < size(grid); ++i) {
                for (int j = 0; j + l - 1 < size(grid[0]); ++j) {
                    if (check(grid, prefix_row, prefix_col, l, i, j)) {
                        return l;
                    }
                }
            }
        }
        return 1;
    }

private:
    bool check(const vector<vector<int>>& grid,
               const vector<vector<int>>& prefix_row,
               const vector<vector<int>>& prefix_col,
               int l, int i, int j) {
        int diag = 0, anti_diag = 0;
        for (int d = 0; d < l; ++d) {
            diag += grid[i + d][j + d];
            anti_diag += grid[i + d][j + l - 1 - d];
        }
        if (diag != anti_diag) {
            return false;
        }
        for (int ni = i; ni < i + l; ++ni) {
            if (diag != get_sum(prefix_row[ni], j, j + l - 1)) {
                return false;
            }
        }
        for (int nj = j; nj < j + l; ++nj) {
            if (diag != get_sum(prefix_col[nj], i, i + l - 1)) {
                return false;
            }
        }
        return true;
    }

    int get_sum(const vector<int>& prefix, int a, int b) {
        return prefix[b + 1] - prefix[a];
    }
};
