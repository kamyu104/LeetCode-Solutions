// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int n = A.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] += *min_element(next(A[i - 1].cbegin(), max(0, j - 1)),
                                        next(A[i - 1].cbegin(), min(j + 2, n)));
            }
        }
        return *min_element(A.back().cbegin(), A.back().cend());
    }
};
