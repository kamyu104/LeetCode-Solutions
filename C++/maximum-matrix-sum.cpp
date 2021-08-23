// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int64_t abs_total = 0, min_abs_val = numeric_limits<int64_t>::max();
        bool is_neg_cnt_odd = false;
        for (int i = 0; i < size(matrix); ++i) {
            for (int j = 0; j < size(matrix[0]); ++j) {
                abs_total += abs(matrix[i][j]);
                min_abs_val = min(min_abs_val, labs(matrix[i][j]));
                if (matrix[i][j] < 0) {
                    is_neg_cnt_odd = !is_neg_cnt_odd;
                }
            }
        }
        return !is_neg_cnt_odd ? abs_total : abs_total - 2 * min_abs_val;
    }
};
