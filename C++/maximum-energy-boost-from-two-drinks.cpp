// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        vector<int64_t> dp(2);
        for (int i = 0; i < size(energyDrinkA); ++i) {
            vector<int64_t> new_dp(2);
            new_dp[0] = max(dp[0] + energyDrinkA[i], dp[1]);
            new_dp[1] = max(dp[1] + energyDrinkB[i], dp[0]);
            dp = move(new_dp);
        }
        return ranges::max(dp);
    }
};
