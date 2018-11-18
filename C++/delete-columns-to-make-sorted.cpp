// Time:  O(n * l)
// Space: O(1)

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0;
        for (int c = 0; c < A[0].size(); ++c) {
            for (int r = 1; r < A.size(); ++r) {
                if (A[r - 1][c] > A[r][c]) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
