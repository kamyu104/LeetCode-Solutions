// Time:  O(n)
// Space: O(n)

// greedy, dp
class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (const auto& r : restrictions)  {
            dp[r[0]] = r[1];
        }
        for (int i = 0; i + 1 < n; ++i) {
            dp[i + 1] = min(dp[i + 1], dp[i] + diff[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = min(dp[i], dp[i + 1] + diff[i]);
        }
        return ranges::max(dp);
    }
};
