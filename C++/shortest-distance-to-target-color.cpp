// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {   
        vector<vector<int>> dp(3, vector<int>(colors.size(), numeric_limits<int>::max()));
        dp[colors[0] - 1][0] = 0;
        for (int i = 1; i < colors.size(); ++i) {
            for (int color = 0; color < 3; ++color) {
                if (dp[color][i - 1] != numeric_limits<int>::max()) {
                    dp[color][i] = dp[color][i - 1] + 1;
                }
            }
            dp[colors[i] - 1][i] = 0;
        }

        dp[colors[colors.size() - 1] - 1][colors.size() - 1] = 0;
        for (int i = colors.size() - 2; i >= 0; --i) {
            for (int color = 0; color < 3; ++color) {
                if (dp[color][i + 1] != numeric_limits<int>::max()) {
                    if (abs(dp[color][i + 1] - 1) < dp[color][i]) {
                        dp[color][i] = dp[color][i + 1] - 1;
                    }
                }
            }
            dp[colors[i] - 1][i] = 0;
        }

        vector<int> result;
        for (const auto& query : queries) {
            const auto d = abs(dp[query[1] - 1][query[0]]);
            result.emplace_back(d != numeric_limits<int>::max() ? d : -1);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {   
        vector<vector<int>> left(3, vector<int>(colors.size(), numeric_limits<int>::max()));
        left[colors[0] - 1][0] = 0;
        for (int i = 1; i < colors.size(); ++i) {
            for (int color = 0; color < 3; ++color) {
                if (left[color][i - 1] != numeric_limits<int>::max()) {
                    left[color][i] = left[color][i - 1] + 1;
                }
            }
            left[colors[i] - 1][i] = 0;
        }

        vector<vector<int>> right(3, vector<int>(colors.size(), numeric_limits<int>::max()));
        right[colors[colors.size() - 1] - 1][colors.size() - 1] = 0;
        for (int i = colors.size() - 2; i >= 0; --i) {
            for (int color = 0; color < 3; ++color) {
                if (right[color][i + 1] != numeric_limits<int>::max()) {
                    right[color][i] = right[color][i + 1] + 1;
                }
            }
            right[colors[i] - 1][i] = 0;
        }

        vector<int> result;
        for (const auto& query : queries) {
            const auto d = min(left[query[1] - 1][query[0]], right[query[1] - 1][query[0]]);
            result.emplace_back(d != numeric_limits<int>::max() ? d : -1);
        }
        return result;
    }
};
