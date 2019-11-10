// Time:  O(n + m)
// Space: O(n + m)

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n), col(m);
        for (const auto& idx : indices) {
            row[idx[0]] ^= 1;
            col[idx[1]] ^= 1;
        }
        int row_sum = accumulate(row.cbegin(), row.cend(), 0);
        int col_sum = accumulate(col.cbegin(), col.cend(), 0);
        return row_sum * m + col_sum * n - 2 * row_sum * col_sum;
    }
};
