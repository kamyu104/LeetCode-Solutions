// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int n = mat.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += mat[i][i] + mat[n - 1 - i][i];
        }
        if (n % 2) {
            result -= mat[n / 2][n / 2];
        }
        return result;
    }
};
