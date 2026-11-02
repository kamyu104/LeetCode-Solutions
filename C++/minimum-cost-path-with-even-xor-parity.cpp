// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        static const int INF = numeric_limits<int>::max();
        
        const auto& parity = [](int x) {
            return popcount(static_cast<uint32_t>(x)) % 2;
        };

        vector<int> mn(size(values), INF);
        int result = INF;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            const auto& i = parity(values[u]), &j = parity(values[v]);
            if (i == j) {
                result = min(result, c);
                continue;
            }
            if (i > j) {
                swap(u, v);
            }
            if (mn[u] != INF) {
                result = min(result, mn[u] + c);
            }
            mn[u] = min(mn[u], c);
        }
        return result != INF ? result : -1;
    }
};

// Time:  O(n)
// Space: O(n)
// iterative dfs, tree dp
class Solution2 {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        static const int INF = numeric_limits<int>::max();
        
        const auto& parity = [](int x) {
            return popcount(static_cast<uint32_t>(x)) % 2;
        };

        const auto& add = [](int x, int y) {
            return x < INF - y ? x + y : INF;
        };

        vector<vector<pair<int, int>>> adj(size(values));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        vector<int> order;
        order.reserve(size(values));
        vector<int> parent(size(values), -2), cost(size(values), -1);
        parent[0] = -1, cost[0] = 0;
        vector<int> stk = {0};
        while (!empty(stk)) {
            const auto u = stk.back(); stk.pop_back();
            order.emplace_back(u);
            for (const auto& [v, c] : adj[u]) {
                if (parent[v] != -2) {
                    continue;
                }
                parent[v] = u, cost[v] = c;
                stk.emplace_back(v);
            }
        }
        vector<vector<int>> dp(size(values), vector<int>(2, INF));
        for (int u = 0; u < size(dp); ++u) {
            dp[u][parity(values[u])] = 0;
        }
        int mn = INF;
        for (int i = size(order) - 1; i >= 1; --i) {
            const auto& v = order[i];
            const int u = parent[v], c = cost[v], p = parity(values[u]);
            mn = min({mn, add(add(dp[u][0], dp[v][0]), c), add(add(dp[u][1], dp[v][1]), c)});
            dp[u] = {min(dp[u][0], add(dp[v][p], c)), min(dp[u][1], add(dp[v][p ^ 1], c))};
        }
        return mn != INF ? mn : -1;
    }
};
