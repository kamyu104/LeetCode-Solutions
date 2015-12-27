// Time:  O(n * k), n is the number of coins, k is the amount of money
// Space: O(k)

// DP solution. (164ms)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> amounts(amount + 1, numeric_limits<int>::max());
        amounts[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            if (amounts[i] != numeric_limits<int>::max()) {
                for (const auto& coin : coins) {
                    if (i + coin <= amount) {
                        amounts[i + coin] = min(amounts[i + coin], amounts[i] + 1);
                    }
                }
            }
        }
        return amounts[amount] == numeric_limits<int>::max() ? -1 : amounts[amount];
    }
};
