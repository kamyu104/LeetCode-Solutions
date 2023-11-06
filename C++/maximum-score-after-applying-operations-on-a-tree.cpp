// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(size(values));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&]() {
            vector<int64_t> dp(size(values));
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back(); 
                if (step == 1) {
                    if (size(adj[u]) == (u ? 1 : 0)) {
                        dp[u] = static_cast<int64_t>(values[u]);
                        continue;
                    }
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v != p) {
                            stk.emplace_back(1, v, u);
                        }
                    }
                } else if (step == 2) {
                    int64_t total = 0;
                    for (const auto& v : adj[u]) {
                        if (v != p) {
                            total += dp[v];
                        }
                    } 
                    dp[u] = min(total, static_cast<int64_t>(values[u]));  // min(pick u, not pick u)
                }
            }
            return dp[0];
        };

        return accumulate(cbegin(values), cend(values), 0ll) - iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(size(values));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const function<int64_t (int, int)> dfs = [&](int u, int p) {
            if (size(adj[u]) == (u ? 1 : 0)) {
                return static_cast<int64_t>(values[u]);
            }
            int64_t total = 0;
            for (const auto& v : adj[u]) {
                if (v != p) {
                    total += dfs(v, u);
                }
            } 
            return min(total, static_cast<int64_t>(values[u]));  // min(pick u, not pick u)
        };

        return accumulate(cbegin(values), cend(values), 0ll) - dfs(0, -1);
    }
};
