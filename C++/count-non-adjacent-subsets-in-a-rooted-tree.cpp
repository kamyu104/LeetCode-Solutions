// Time:  O(n * k^2)
// Space: O(n * k)
// if k is large, the per-merge cyclic convolution can be done in O(klogk) via NTT + CRT, Time: O(n * klogk), Space: O(n * k) in total

// topological sort, tree dp
class Solution {
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        
        const auto& merge = [&](const auto& a, const auto& b) {
            vector<int> result(size(a));
            for (int i = 0; i < k; ++i) {
                if (!a[i]) {
                    continue;
                }
                for (int j = 0; j < k; ++j) {
                    if (!b[j]) {
                        continue;
                    }
                    result[(i + j) % k] = ((result[(i + j) % k] + static_cast<int64_t>(a[i]) * b[j]) % MOD);
                }
            }
            return result;
        };

        vector<vector<int>> adj(size(nums));
        for (int v = 1; v < size(parent); ++v) {
            adj[parent[v]].emplace_back(v);
        }
        vector<vector<vector<int>>> dp(size(nums), vector<vector<int>>(2, vector<int>(k)));
        for (int u = size(nums) - 1; u >= 0; --u) {
            vector<vector<int>> new_dp(2, vector<int>(k));
            new_dp[0][0] = 1;
            new_dp[1][nums[u] % k] = 1;
            for (const auto& v : adj[u]) {
                vector<int> dp2(k);
                for (int i = 0; i < k; ++i) {
                    dp2[i] = (dp[v][0][i] + dp[v][1][i]) % MOD;
                }
                new_dp[0] = merge(new_dp[0], dp2);
                new_dp[1] = merge(new_dp[1], dp[v][0]);
            }
            dp[u] = move(new_dp);
        }
        return ((dp[0][0][0] + dp[0][1][0] - 1LL) + MOD) % MOD;
    }
};
