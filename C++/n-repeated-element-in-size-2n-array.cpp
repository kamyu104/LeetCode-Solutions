// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 2; i < A.size(); ++i) {
            if (A[i - 1] == A[i] || A[i - 2] == A[i])  {
                return A[i];
            }
        }
        return A[0];
    }
};
