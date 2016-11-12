// Time:  O(n^2)
// Space: O(n * d)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<unordered_map<long long, int>> dp(A.size());
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                const auto diff = static_cast<long long>(A[i]) - A[j];
                ++dp[i][diff];
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};
