// Time:  O(n^2)
// Space: O(n * d)

class Solution_TLE {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<unordered_map<long long, int>> dp(A.size());
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][static_cast<long long>(A[i]) - A[j]] += dp[j][static_cast<long long>(A[i]) - A[j]] + 1;
                result += dp[j][static_cast<long long>(A[i]) - A[j]];
            }
        }
        return result;
    }
};
