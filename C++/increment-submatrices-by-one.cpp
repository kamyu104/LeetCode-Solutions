// Time:  O(q + n^2)
// Space: O(1)

// line sweep, difference matrix (2d difference array)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n, vector<int>(n));
        for (const auto& op : queries) {
            ++result[op[0]][op[1]];
            if (op[3] + 1 < size(result[0])) {
                --result[op[0]][op[3] + 1];
            }
            if (op[2] + 1 < size(result)) {
                --result[op[2] + 1][op[1]];
            }
            if (op[2] + 1 < size(result) && op[3] + 1 < size(result[0])) {
                ++result[op[2] + 1][op[3] + 1];
            }
        }
        for (int r = 0; r < size(result); ++r) {
            for (int c = 0; c + 1 < size(result[0]); ++c) {
                result[r][c + 1] += result[r][c];
            }
        }
        for (int r = 0; r + 1 < size(result); ++r) {
            for (int c = 0; c < size(result[0]); ++c) {
                result[r + 1][c] += result[r][c];
            }
        }
        return result;
    }
};
