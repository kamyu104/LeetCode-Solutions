// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {   
        vector<vector<int>> dp(3, vector<int>(colors.size(), -1));
        dp[colors[0] - 1][0] = 0;
        for (int i = 1; i < colors.size(); ++i) {
            for (int color = 0; color < 3; ++color) {
                dp[color][i] = dp[color][i - 1];
            }
            dp[colors[i] - 1][i] = i;
        }

        dp[colors[colors.size() - 1] - 1][colors.size() - 1] = colors.size() - 1;
        for (int i = colors.size() - 2; i >= 0; --i) {
            for (int color = 0; color < 3; ++color) {
                if (dp[color][i + 1] != -1) {
                    continue;
                }
                if (dp[color][i] == -1 ||
                    abs(dp[color][i + 1] - i) < abs(dp[color][i] - i)) {
                    dp[color][i] = dp[color][i + 1];
                }
            }
            dp[colors[i] - 1][i] = i;
        }

        vector<int> result;
        for (const auto& query : queries) {
            const auto d = abs(dp[query[1] - 1][query[0]]);
            result.emplace_back(dp[query[1] - 1][query[0]] != -1 ? abs(dp[query[1] - 1][query[0]] - query[0]) : -1);
        }
        return result;
    }
};
