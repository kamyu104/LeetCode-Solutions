// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(k)

// DP solution. (164ms)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            if (dp[i] != numeric_limits<int>::max()) {
                for (const auto& coin : coins) {
                    if (coin <= numeric_limits<int>::max() - i && i + coin <= amount) {
                        dp[i + coin] = min(dp[i + coin], dp[i] + 1);
                    }
                }
            }
        }
        return dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount];
    }
};
