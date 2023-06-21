// Time:  O(n^2)
// Space: O(n)

// knapsack dp
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(size(cost) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(cost); ++i) {
            for (int j = size(cost); j >= 1; --j) {
                if (dp[max(j - (time[i] + 1), 0)] != INF) {
                    dp[j] = min(dp[j], dp[max(j - (time[i] + 1), 0)] + cost[i]);
                }
            }
        }
        return dp.back();
    }
};
