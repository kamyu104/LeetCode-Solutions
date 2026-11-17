// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        const auto& iter_dfs = [&]() {
            vector<int> order;
            order.reserve(n);
            vector<int> parent(n, -2);
            parent[0] = -1;
            vector<int> stk = {0};
            while (!empty(stk)) {
                const auto u = stk.back(); stk.pop_back();
                order.emplace_back(u);
                for (const auto& v : adj[u]) {
                    if (parent[v] != -2) {
                        continue;
                    }
                    parent[v] = u;
                    stk.emplace_back(v);
                }
            }
            return pair(order, parent);
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& [order, parent] = iter_dfs();
        int64_t total = 0, mn = 0;
        vector<int64_t> dp1(n, 1), dp2(n);
        for (const auto& u : order | views::reverse) {
            for (const auto& v : adj[u]) {
                if (v == parent[u]) {
                    continue;
                }
                dp1[u] += dp1[v];
                if (dp2[v] < 0) {
                    dp2[u] += dp2[v];
                }
            }
            if (colors[u] == 'R') {
                total += dp1[u];
                dp2[u] += -dp1[u];
            } else {
                dp2[u] += dp1[u];
            }
            if (dp2[u] < mn) {
                mn = dp2[u];
            }
        }
        return total + mn;
    }
};
