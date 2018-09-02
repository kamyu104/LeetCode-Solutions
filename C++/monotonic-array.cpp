// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = false, dec = false;
        for (int i = 0; i + 1 < A.size(); ++i) {
            if (A[i] < A[i + 1]) {
                inc = true;
            } else if (A[i] > A[i + 1]) {
                dec = true;
            }
        }
        return !inc || !dec;
    }
};
