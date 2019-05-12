// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const auto W = K + 1;
        vector<int> dp(W);
        for (int i = 0; i < A.size(); ++i) {
            int curr_max = 0;
            // dp[i % W] = 0;  // no need in this problem
            for (int k = 1; k <= min(K, i + 1); ++k) {
                curr_max = max(curr_max, A[i - k + 1]);
                dp[i % W] = max(dp[i % W], (i >= k ? dp[(i - k) % W] : 0) + curr_max * k);
            }
        }
        return dp[(A.size() - 1) % W];
    }
};
