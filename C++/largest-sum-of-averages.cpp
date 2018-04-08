// Time:  O(k * n^2)
// Space: O(n)

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> accum_sum;
        accum_sum.emplace_back(A[0]);
        for (int i = 1; i < A.size(); ++i) {
            accum_sum.emplace_back(A[i] + accum_sum.back());
        }

        vector<vector<double>> dp(2, vector<double>(A.size()));
        for (int k = 1; k <= K; ++k) {
            for (int i = k - 1; i < A.size(); ++i) {
                if (k == 1) {
                    dp[k % 2][i] = static_cast<double>(accum_sum[i]) / (i + 1);
                } else {
                    for (int j = k - 2 ; j < i; ++j) {
                        dp[k % 2][i] = max(dp[k % 2][i],
                                           dp[(k - 1) % 2][j] +
                                           static_cast<double>(accum_sum[i] - accum_sum[j]) / (i - j));
                    }
                }
            }
        }
        return dp[K % 2].back();
    }
};
