// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        static const int M = 1e9 + 7;
        sort(A.begin(), A.end());
        unordered_map<int, int64_t> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0 && dp.count(A[i] / A[j])) {
                   dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % M;
                }
            }
        }
        return accumulate(dp.cbegin(), dp.cend(), 0L,
                          [](int64_t x, const pair<int, int>& p) {
                              return x + p.second;
                          }) % M;
    }
};
