// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size()));
        for (int p = 3; p <= A.size(); ++p) {
            for (int i = 0; i + p - 1 < A.size(); ++i) {
                int j = i + p - 1;
                dp[i][j] = numeric_limits<int>::max();
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
                }
            }
        }
        return dp[0][A.size() - 1];
    }
};
