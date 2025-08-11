// Time:  O(n * w1 * w2)
// Space: O(w1 * w2)

// dp
class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        vector<vector<bool>> dp(w1 + 1, vector<bool>(w2 + 1)), new_dp(w1 + 1, vector<bool>(w2 + 1));
        dp[0][0] = true;
        for (const auto& w : weights) {
            for (int i = 0; i <= w1; ++i) {
                for (int j = 0; j <= w2; ++j) {
                    new_dp[i][j] = dp[i][j] || (i - w >= 0 && dp[i - w][j]) || (j - w >= 0 && dp[i][j - w]);
                }
            }
            swap(dp, new_dp);
        }
        int result = 0;
        for (int i = 0; i <= w1; ++i) {
            for (int j = w2; j >= 0; --j) {
                if (dp[i][j]) {
                    result = max(result, i + j);
                    break;
                }
            }
        }
        return result;
    }
};
