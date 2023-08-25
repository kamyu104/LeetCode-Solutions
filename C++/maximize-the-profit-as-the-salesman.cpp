// Time:  O(n + m), m = len(offers)
// Space: O(n + m)

// dp
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<vector<pair<int, int>>> lookup(n);
        for (const auto& x : offers) {
            lookup[x[1]].emplace_back(x[0], x[2]);
        }
        vector<int> dp(n + 1);
        for (int e = 0; e < n; ++e) {
            dp[e + 1] = dp[(e - 1) + 1];
            for (const auto& [s, g] : lookup[e]) {
                dp[e + 1] = max(dp[e + 1], dp[(s - 1) + 1] + g);
            }
        }
        return dp.back();
    }
};
