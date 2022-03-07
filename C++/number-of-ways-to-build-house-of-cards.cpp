// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(n + 1);  // dp[i]: number of ways with i cards and at most t triangles in the first row
        dp[0] = 1;
        for (int t = 1; t <= (n + 1) / 3; ++t) {
            for (int i = n; i >= 3 * t - 1; --i) {
                dp[i] += dp[i - (3 * t - 1)];
            }
        }
        return dp[n];
    }
};

// Time:  O(n^3)
// Space: O(n^2)
// dp
class Solution_TLE {
public:
    int houseOfCards(int n) {
        vector<vector<int>> dp((n + 1) / 3 + 1, vector<int>(n + 1));  // dp[t][i]: number of ways with i cards and t triangles in the lowest row
        dp[0][0] = 1;
        for (int t = 1; t <= (n + 1) / 3; ++t) {
            for (int i = 3 * t - 1; i <= n; ++i) {
                for (int j = 0; j < t; ++j) {
                    dp[t][i] += dp[j][i - (3 * t - 1)];
                }
            }
        }
        return accumulate(cbegin(dp), cend(dp), 0,
                          [](const auto& total, const auto& x) {
                              return total + x.back();
                          });
    }
};
