// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size()));
        for (int l = 1; l <= arr.size(); ++l) {
            for (int i = 0; i + l - 1 < arr.size(); ++i) {
                int j = i + l - 1;
                if (l == 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + dp[i + 1][j];
                    if (arr[i] == arr[i + 1]) {
                        dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
                    }
                    for (int k = i + 2; k <= j; ++k) {
                        if (arr[i] == arr[k]) {
                            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                        }
                    }
                }
            }
        }
        return dp[0][arr.size() - 1]; 
    }
};
