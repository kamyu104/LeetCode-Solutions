// Time:  O(n * 2^n)
// Space: O(2^n)

// dp, bitmasks
class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> adj(n);
        for (const auto& e : edges) {
            adj[e[1]] |= 1 << e[0];
        }
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < size(dp); ++mask) {
            if (dp[mask] == -1) {
                continue;
            }
            const int l = __builtin_popcount(mask) + 1;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }
                if ((mask & adj[i]) == adj[i]) {
                    dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + l * score[i]);
                }
            }
        }
        return dp.back();
    }
};
