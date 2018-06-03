// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int result = 0, up_len = 0, down_len = 0;
        for (int i = 1; i < A.size(); ++i) {
            if ((down_len && A[i - 1] < A[i]) ||
                A[i - 1] == A[i]) {
                up_len = down_len = 0;
            }
            up_len += A[i - 1] < A[i];
            down_len += A[i - 1] > A[i];
            if (up_len && down_len) {
                result= max(result, up_len + down_len + 1);
            }
        }
        return result;
    }
};
