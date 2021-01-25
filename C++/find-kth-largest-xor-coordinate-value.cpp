// Time:  O(m * n) on average
// Space: O(m * n)

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> vals;
        for (int r = 0; r < size(matrix); ++r) {
            int curr = 0;
            for (int c = 0; c < size(matrix[0]); ++c) {
                curr = curr ^ matrix[r][c];
                if (r == 0) {
                    matrix[r][c] = curr;
                } else {
                    matrix[r][c] = curr ^ matrix[r - 1][c];
                }
                vals.emplace_back(matrix[r][c]);
            }
        }
        nth_element(begin(vals), begin(vals) + k - 1, end(vals), greater<int>());
        return vals[k - 1];
    }
};
