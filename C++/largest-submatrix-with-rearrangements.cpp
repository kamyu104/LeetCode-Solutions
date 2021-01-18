// Time:  O(m * nlogn)
// Space: O(1)

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int resuilt = 0;
        for (int c = 0; c < size(matrix[0]); ++c) {
            int h = 0;
            for (int r = 0; r < size(matrix); ++r) {
                h = (matrix[r][c] == 1) ? h + 1 : 0;
                matrix[r][c] = h;
            }
        }
        int result = 0;
        for (auto& row : matrix) {
            sort(begin(row), end(row));
            for (int c = 0; c < size(row); ++c) {
                result = max(result, int(size(row) - c) * row[c]);
            }
        }
        return result;
    }
};
