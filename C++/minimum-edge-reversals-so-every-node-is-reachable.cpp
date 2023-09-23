// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> adj;
        for (const auto& e : edges) {
            adj[e[0]][e[1]] = 0;
            adj[e[1]][e[0]] = 1;
        }
        const auto& iter_dfs1 = [&]() {
            int result = 0;
            vector<pair<int, int>> stk = {{0, -1}};
            while (!empty(stk)) {
                const auto [u, p] = stk.back(); stk.pop_back();
                for (const auto& [v, _] : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    result += adj[u][v];
                    stk.emplace_back(v, u);
                }
            }
            return result;
        };

        const auto& iter_dfs2 = [&](int curr) {
            vector<int> result(n, -1);
            vector<pair<int, int>> stk = {{0, curr}};
            while (!empty(stk)) {
                const auto [u, curr] = stk.back(); stk.pop_back();
                result[u] = curr;
                for (const auto& [v, _] : adj[u]) {
                    if (result[v] == -1) {
                        stk.emplace_back(v, curr - adj[u][v] + adj[v][u]);
                    }
                }
            }
            return result;
        };

        return iter_dfs2(iter_dfs1());
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_map<int, int>> adj;
        for (const auto& e : edges) {
            adj[e[0]][e[1]] = 0;
            adj[e[1]][e[0]] = 1;
        }
        const function<int (int, int)> dfs1 = [&](int u, int p) {
            int result = 0;
            for (const auto& [v, _] : adj[u]) {
                if (v != p) {
                    result += adj[u][v] + dfs1(v, u);
                }
            }
            return result;
        };

        vector<int> result(n, -1);
        const function<void (int, int)> dfs2 = [&](int u, int curr) {
            result[u] = curr;
            for (const auto& [v, _] : adj[u]) {
                if (result[v] == -1) {
                    dfs2(v, curr - adj[u][v] + adj[v][u]);
                }
            }
        };

        dfs2(0, dfs1(0, -1));
        return result;
    }
};
