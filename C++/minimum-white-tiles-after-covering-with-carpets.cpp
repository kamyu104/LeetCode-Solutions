// Time:  O(m * n)
// Space: O(m * n)

// dp
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        vector<vector<int>> dp(size(floor) + 1, vector<int>(numCarpets + 1));  // dp[i][j] : min number of white tiles in the first i floors with j carpets
        for (int i = 1; i < size(dp); ++i) {
            dp[i][0] = dp[i - 1][0] + static_cast<int>(floor[i - 1] == '1');
            for (int j = 1; j <= numCarpets; ++j) {
                dp[i][j] = min(dp[i - 1][j] + static_cast<int>(floor[i - 1] == '1'),
                               dp[max(i - carpetLen, 0)][j - 1]);
            }
        }
        return dp.back().back();
    }
};
