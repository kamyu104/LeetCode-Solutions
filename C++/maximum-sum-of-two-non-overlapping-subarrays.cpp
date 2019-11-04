// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); ++i) {
            A[i] += A[i - 1];
        }
        int result = A[L + M - 1], L_max = A[L - 1], M_max = A[M - 1];
        for (int i = L + M; i < A.size(); ++i) {
            L_max = max(L_max, A[i - M] - A[i - L - M]);
            M_max = max(M_max, A[i - L] - A[i - L - M]);
            result = max(result,
                         max(L_max + A[i] - A[i - M],
                             M_max + A[i] - A[i - L]));
        }
        return result;
    }
};
