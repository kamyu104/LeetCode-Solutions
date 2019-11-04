// Time:  O(m * n)
// Space: O(min(m, n))

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size()) {
            return maxUncrossedLines(B, A);
        }
        vector<vector<int>> dp(2, vector<int>(B.size() + 1));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j] + static_cast<int>(A[i] == B[j]),
                                             max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]));
            }
        }
        return dp[(A.size()) % 2][B.size()];
    }
};
