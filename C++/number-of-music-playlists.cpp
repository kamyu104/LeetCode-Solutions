// Time:  O(n * l)
// Space: O(l)

// Another better solution (generating function), you could refer to 
// https://leetcode.com/problems/number-of-music-playlists/solution/
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        static const int M = 1000000007;
        vector<vector<uint64_t>> dp(2, vector<uint64_t>(1 + L, 0ull));
        dp[0][0] = dp[1][1] = 1;
        for (int n = 1; n <= N; ++n) {
            dp[n % 2][n] = (dp[(n - 1) % 2][n - 1] * n) % M;
            for (int l = n + 1; l <= L; ++l) {
                dp[n % 2][l] = ((dp[n % 2][l - 1] * max(n - K, 0)) % M +
                                (dp[(n - 1) % 2][l - 1] * n) % M) % M;
            }
        }
        return dp[N % 2][L];
    }
};
