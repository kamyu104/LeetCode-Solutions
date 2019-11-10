// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> upper_matrix(colsum.size());
        vector<int> lower_matrix(colsum.size());
        for (int i = 0; i < colsum.size(); ++i) {
            upper_matrix[i] = int(upper > 0 && colsum[i] > 0);
            lower_matrix[i] = colsum[i] - upper_matrix[i];
            upper -= upper_matrix[i];
            lower -= lower_matrix[i];
        }
        if (upper != 0 || lower != 0) {
            return {};
        }
        return {upper_matrix, lower_matrix};
    }
};
