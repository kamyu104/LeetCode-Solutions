// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int result = 0, i = 0;
        for (int j = 0; j < A.size(); ++j) {
            K -= (A[j] == 0) ? 1 : 0;
            while (K < 0) {
                K += (A[i] == 0) ? 1 : 0;
                ++i;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};
