// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> coins;
        coins.emplace_back(1);
        for (const auto& n : nums) {
            if (n > 0) {
                coins.emplace_back(n);
            }
        }
        coins.emplace_back(1);
    
        vector<vector<int>> max_coins(coins.size(), vector<int>(coins.size()));
        for (int k = 2; k < coins.size(); ++k) {
            for (int left = 0; left < coins.size() - k; ++left) {
                const int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    max_coins[left][right] = max(max_coins[left][right],
                         coins[left] * coins[i] * coins[right] +
                         max_coins[left][i] + max_coins[i][right]);
                }
            }
        }
    
        return max_coins[0][coins.size() - 1];
    }
};
