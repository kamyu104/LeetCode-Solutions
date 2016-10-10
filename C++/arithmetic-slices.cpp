// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, i = 0;
        for (int i = 0; i + 2 < A.size(); ++i) {
            const auto start = i;
            while (A[i + 2] + A[i] == 2 * A[i + 1]) {
                res += (i++) - start + 1;
            }
        }
        return res;
    }
};
