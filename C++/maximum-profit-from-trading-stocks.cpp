// Time:  O(n * b)
// Space: O(b)

// dp, optimized from solution2
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        vector<int> dp(budget + 1);
        for (int i = 0; i < size(present); ++i) {
            if (future[i] - present[i] < 0) {
                continue;
            }
            for (int b = budget; b >= present[i]; --b) {
                dp[b] = max(dp[b], dp[b - present[i]] + (future[i] - present[i]));
            }
        }
        return dp.back();
    }
};

// Time:  O(n * b)
// Space: O(b)
// dp
class Solution2 {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        vector<vector<int>> dp(2, vector<int>(budget + 1));
        for (int i = 0; i < size(present); ++i) {
            for (int b = 0; b <= budget; ++b) {
                dp[(i + 1) % 2][b] = max(dp[i % 2][b], b - present[i] >= 0 ? dp[i % 2][b - present[i]] + (future[i] - present[i]) : 0);
            }
        }
        return dp[size(present) % 2].back();
    }
};
