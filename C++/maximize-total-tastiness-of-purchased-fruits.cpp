// Time:  O(n * a * c), n = len(price), a = maxAmount, c = maxCoupons
// Space: O(a * c)

// dp
class Solution {
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        vector<vector<int>> dp(maxAmount + 1, vector<int>(maxCoupons + 1));
        for (int k = 0; k < size(price); ++k) {
            for (int i = maxAmount; i - price[k] / 2 >= 0; --i) {
                for (int j = maxCoupons; j >= 0; --j) {
                    if (i - price[k] >= 0) {
                        dp[i][j] = max(dp[i][j], tastiness[k] + dp[i - price[k]][j]);
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] = max(dp[i][j], tastiness[k] + dp[i - price[k] / 2][j - 1]);
                    }
                }
            }
        }
        return dp[maxAmount][maxCoupons];
    }
};
