// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        int result = 2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j)  {
                int v = A[j] - A[i];
                dp[v][j] = max(dp[v][j], dp[v][i] + 1);
                result = max(result, dp[v][j] + 1);
            }
        }
        return result;
    }
};
