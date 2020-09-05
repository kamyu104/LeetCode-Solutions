// Time:  O(n^2 * f)
// Space: O(n * f)

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1));
        dp[start][fuel] = 1;
        for (int k = fuel; k >= 0; --k) {
            for (int i = 0; i < locations.size(); ++i) {
                for (int j = 0; j < locations.size(); ++j) {
                    if (i == j) {
                        continue;
                    }
                    int amount = abs(locations[i] - locations[j]);
                    if (k + amount > fuel) {
                        continue;
                    }
                    dp[i][k] = (dp[i][k] + dp[j][k + amount]) % MOD;
                }
            }
        }
        return accumulate(cbegin(dp[finish]), cend(dp[finish]), 0LL,
                          [&](const int64_t a, const int b) {
                              return (a + b) % MOD;
                          });
    }
};
