// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        if (m == 0) {
            return false;
        }
        const int n = matrix[0].size();
        if  (n == 0) {
            return false;
        }
        int count = 0;

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }

        return false;
    }
};
