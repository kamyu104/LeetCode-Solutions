// Time:  O(m + n), excluding ctor of result
// Space: O(1)

// optimized from Solution2 since we can find next i, j pair without nested loops
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(size(rowSum), vector<int>(size(colSum)));
        for (int i = 0, j = 0; i < size(matrix) && j < size(matrix[0]);) {
            matrix[i][j] = min(rowSum[i], colSum[j]);  // greedily used
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];
            if (!rowSum[i]) {  // won't be used in row i, ++i
                ++i;
            }
            if (!colSum[j]) {  // won't be used in col j, ++j
                ++j;
            }
        }
        return matrix;
    }
};

// Time:  O(m * n)
// Space: O(1)
class Solution2 {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(size(rowSum), vector<int>(size(colSum)));
        for (int i = 0; i < size(matrix); ++i) {
            for (int j = 0 ;j < size(matrix[0]); ++j) {
                matrix[i][j] = min(rowSum[i], colSum[j]);  // greedily used
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
        return matrix;
    }
};
