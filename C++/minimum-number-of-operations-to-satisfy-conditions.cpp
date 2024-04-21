// Time:  O(n * (m + 100))
// Space: O(10)

// dp
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        static const int INF = numeric_limits<int>::max();
        static const int MAX_VALUE = 9;
    
        vector<int> dp(MAX_VALUE + 1);
        for (int j = 0; j < size(grid[0]); ++j) {
            vector<int> cnt(MAX_VALUE + 1);
            for (int i = 0; i < size(grid); ++i) {
                ++cnt[grid[i][j]];
            }
            vector<int> new_dp(MAX_VALUE + 1, INF);
            for (int i = 0; i <= MAX_VALUE; ++i) {
                int mn = INF;
                for (int k = 0; k <= MAX_VALUE; ++k) {
                    if (k != i) {
                        mn = min(mn, dp[k]);
                    }
                }
                new_dp[i] = min(new_dp[i], mn + (static_cast<int>(size(grid)) - cnt[i]));
            }
            dp = move(new_dp);
        }
        return *min_element(begin(dp), end(dp));
    }
};
