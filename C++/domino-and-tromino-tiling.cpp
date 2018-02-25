// Time:  O(n)
// Space: O(1)

// Prove:
// dp[n] = dp[n-1](|) + dp[n-2](=) + 2*(dp[n-3](「」) + ... + d[0](「 = ... = 」))
//       = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
//       = dp[n-1] + dp[n-3] + (dp[n-2] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
//       = dp[n-1] + dp[n-3] + dp[n-1]
//       = 2*dp[n-1] + dp[n-3]

class Solution {
public:
    int numTilings(int N) {
        const int M = 1e9 + 7;
        vector<int> dp(3);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= N; ++i) {
            dp[i % 3] = (2 * dp[(i - 1) % 3] % M + dp[(i - 3) % 3]) % M;
        }
        return dp[N % 3];
    }
};
