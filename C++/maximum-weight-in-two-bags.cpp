// Time:  O(n * w1 * w2)
// Space: O(w1 * w2)

// dp, bitset
class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        static const int MAX_W = 300;

        vector<bitset<MAX_W + 1>> dp(w1 + 1), new_dp(w1 + 1);
        dp[0][0] = 1;
        for (const auto& w : weights) {
            new_dp = dp;
            for (int i = 0; i <= w1; ++i) {
                if (i - w >= 0) {
                    new_dp[i] |= dp[i - w];
                }
                new_dp[i] |= dp[i] << w;
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

// Time:  O(n * w1 * w2)
// Space: O(w1 * w2)
// dp
class Solution2 {
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
