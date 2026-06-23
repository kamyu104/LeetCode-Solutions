// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        static const auto& POS_INF = numeric_limits<int64_t>::max();
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        vector<vector<int>> adj(n);
        const auto iter_dfs = [&]() {
            vector<int64_t> dp(n);
            vector<pair<int, int>> stk = {{1, 0}};
            while (!empty(stk)) {
                const auto [step, u] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u);
                    for (const auto& v : adj[u]) {
                        stk.emplace_back(1, v);
                    }
                } else if (step == 2) {
                    auto mx = numeric_limits<int64_t>::min();
                    auto mn = numeric_limits<int64_t>::max();
                    for (const auto& v : adj[u]) {
                        mx = max(mx, dp[v]);
                        mn = min(mn, dp[v]);
                    }
                    dp[u] = (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u];
                }
            }
            return dp[0];
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
        }
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        static const auto& POS_INF = numeric_limits<int64_t>::max();
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        vector<vector<int>> adj(n);
        const auto dfs = [&](this auto&& dfs, int u) -> int64_t {
            auto mx = NEG_INF, mn = POS_INF;
            for (const auto& v : adj[u]) {
                const auto& ret = dfs(v);
                mx = max(mx, ret);
                mn = min(mn, ret);
            }
            return (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u];
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
        }
        return dfs(0);
    }
};
