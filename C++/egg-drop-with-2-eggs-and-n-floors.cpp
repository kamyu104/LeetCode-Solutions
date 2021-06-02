// Time:  O(1)
// Space: O(1)

// see the proof: https://www.geeksforgeeks.org/puzzle-set-35-2-eggs-and-100-floors/
class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1 + sqrt(1 + 8 * n)) / 2);    
    }
};

// Time:  O(k * n^2)
// Space: O(n)
class Solution2 {
public:
    int twoEggDrop(int n) {
        static const int K = 2;
        vector<vector<int>> dp(2, vector<int>(n + 1, numeric_limits<int>::max()));
        for (int j = 0; j <= n; ++j) {
            dp[1][j] = j;
        }
        for (int i = 2; i <= K; ++i) {
            dp[i % 2][0] = 0;
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= j; ++k) {
                    dp[i % 2][j] = min(dp[i % 2][j], 1 + max(dp[(i - 1) % 2][k - 1], dp[i % 2][j - k]));
                }
            }
        }
        return dp[K % 2][n];
    }
};
