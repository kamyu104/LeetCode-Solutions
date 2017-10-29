// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) { 
            return findLength(B, A);
        }
        int result = 0;
        vector<vector<int>> dp(2, vector<int>(B.size() + 1));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
                    result = max(result, dp[(i + 1) % 2][j + 1]);
                } else {
                    dp[(i + 1) % 2][j + 1] = 0;
                }
            }
        }
        return result;
    }
};
