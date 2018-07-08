// Time:  O(r * c)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size(), vector<int>(A.size()));
        for (int r = 0; r < A.size(); ++r) {
            for (int c = 0; c < A[0].size(); ++c) {
                result[c][r] = A[r][c];
            }
        }
        return result;
    }
};
