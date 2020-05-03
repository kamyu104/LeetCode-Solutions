// Time:  O(h * 2^n)
// Space: O(2^n)

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        static const int MOD = 1e9 + 7;
        static const int HAT_SIZE = 40;

        vector<vector<int>> hat_to_people(HAT_SIZE);
        for (int i = 0; i < hats.size(); ++i) {
            for (const auto& hat: hats[i]) {
                hat_to_people[hat - 1].emplace_back(i);
            }
        }
        vector<int> dp(1 << hats.size());
        dp[0] = 1;    
        for (const auto& people : hat_to_people) {
            for (int mask = dp.size() - 1; mask >= 0; --mask) {
                for (const int& p: people) {
                    if (mask & (1 << p)) {
                        continue;
                    }
                    dp[mask | (1 << p)] += dp[mask];
                    dp[mask | (1 << p)] %= MOD;
                }
            }
        }
        return dp.back();
    }
};
