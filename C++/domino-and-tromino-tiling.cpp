// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numTilings(int N) {
        const int M = 1e9 + 7;
        vector<int> dp(3);
        dp[1] = 1, dp[2] = 1;
        for (int i = 3; i <= N + 1; ++i) {
            dp[i % 3] = (2 * dp[(i - 1) % 3] % M + dp[(i - 3) % 3]) % M;
        }
        return dp[(N + 1) % 3];
    }
};
