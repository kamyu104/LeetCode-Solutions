// Time:  O(m * n * log(m * n))
// Space: O(m * n)

// sort, dp
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        map<int, vector<pair<int, int>>> lookup;
        for (int i = 0; i < size(mat); ++i) {
            for (int j = 0; j < size(mat[0]); ++j) {
                lookup[mat[i][j]].emplace_back(i, j);
            }
        }
        vector<vector<int>> dp(size(mat), vector<int>(size(mat[0])));
        vector<int> row(size(mat)), col(size(mat[0]));
        for (const auto& [_, pairs] : lookup) {
            for (const auto& [i, j] : pairs) {
                dp[i][j] = max(row[i], col[j]) + 1;
            }
            for (const auto& [i, j] : pairs) {
                row[i] = max(row[i], dp[i][j]);
                col[j] = max(col[j], dp[i][j]);
            }
        }
        return *max_element(cbegin(row), cend(row));
    }
};
