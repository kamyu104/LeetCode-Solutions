// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> accu(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                accu[i + 1][j + 1] = accu[i + 1][j] + accu[i][j + 1] - accu[i][j] + mat[i][j];
            }
        }
        vector<vector<int>> result(m, vector<int>(n));    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r1 = max(i - K, 0), c1 = max(j - K, 0);
                int r2 = min(i + K + 1, m), c2 = min(j + K + 1, n);
                result[i][j] = accu[r2][c2] - accu[r1][c2] - accu[r2][c1] + accu[r1][c1];
            }
        }
        return result;
    }
};
