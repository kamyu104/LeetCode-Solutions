// Time:  O(n)
// Space: O(n)

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) {
            return 1.0f;
        }
        vector<double> dp(N + 1);
        dp[0] = 1.0f;
        double W_sum = 1.0f, result = 0.0f;
        for (int i = 1; i <= N; ++i) {
            dp[i] = W_sum / W;
            if (i < K) {
                W_sum += dp[i];
            } else {
                result += dp[i];
            }
            if (i - W >= 0) {
                W_sum -= dp[i - W];
            }
        }
        return result;
    }
};
