// Time:  O(n * k)
// Space: O(k)

class Solution {
public:
    int kInversePairs(int n, int k) {
        static const int M = 1000000007;
        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i % 2] = vector<int>(k + 1);
            dp[i % 2][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i % 2][j] = (dp[i % 2][j - 1] + dp[(i - 1) % 2][j]) % M;
                if (j - i >= 0) {
                    dp[i % 2][j] = (dp[i % 2][j] - dp[(i - 1) % 2][j - i] + M) % M; 
                }
            }
        }
        return dp[n % 2][k];
    }
};

