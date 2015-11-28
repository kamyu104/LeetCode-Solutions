// Time:  O(m * n * l), A is m x n matrix, B is n x l matrix
// Space: O(m * l)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int m = A.size(), n = A[0].size(), l = B[0].size();
        vector<vector<int>> res(m, vector<int>(l));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < l; ++j) {
                        res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};
