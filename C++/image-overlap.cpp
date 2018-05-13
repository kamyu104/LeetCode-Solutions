// Time:  O(n^4)
// Space: O(n^2)

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> count(pow(2 * A.size() - 1, 2));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if  (!A[i][j]) {
                    continue;
                }
                for (int m = 0; m < B.size(); ++m) {
                   for (int n = 0; n < B[m].size(); ++n) {
                        if (!B[m][n]) {
                            continue;
                        }
                        ++count[(A.size() - 1 + i - m) * (2 * A.size() - 1) +
                                 A.size() - 1 + j - n];
                   }
                }
            }
        }
        return *max_element(count.cbegin(), count.cend());
    }
};
