// Time:  O(n * l^2)
// Space: O(l)

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(A[0].length(), 1);
        for (int j = 0; j < A[0].length(); ++j) {
            for (int i = 0; i < j; ++i) {
                int k = 0;
                for (; k < A.size(); ++k) {
                    if (A[k][i] > A[k][j]) {
                        break;  
                    }
                }
                if (k == A.size()) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return A[0].length() - *max_element(dp.begin(), dp.end());
    }
};
