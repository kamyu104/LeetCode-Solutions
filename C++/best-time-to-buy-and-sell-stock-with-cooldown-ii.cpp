// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int cooldown, vector<int>& costs) {
        vector<int> dp(size(prices) + 1);
        for (int j = 0; j < size(prices); ++j) {
            int mx = dp[j];
            for (int i = 0; i < j; ++i) {
                mx = max(mx, dp[max((i + 1) - (cooldown + 1), 0)] + prices[j] - prices[i] - costs[j - i]);
            }
            dp[j + 1] = mx;
        }
        return dp.back();
    }
};
