// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int left = A.size() - 2, right = A.size() - 1;
        for (; left >= 0 && A[left] <= A[left + 1]; --left);
        if (left < 0) {
            return A;
        }
        for (; A[left] <= A[right]; --right);
        for (; A[right - 1] == A[right]; --right);
        swap(A[left], A[right]);
        return A;
    }
};
