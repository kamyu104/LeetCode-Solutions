// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> B(A);
        for (int i = A.size() - 2; i > 0; --i) {
            B[i] = min(B[i], B[i + 1]);
        }
        int p_max = 0;
        for (int i = 1; i < A.size(); ++i) {
            p_max = max(p_max, A[i - 1]);
            if (p_max <= B[i]) {
                return i;
            }
        }
    }
};
