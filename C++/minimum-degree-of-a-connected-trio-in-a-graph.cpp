// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        vector<int> degree(n + 1);
        for (const auto &e: edges) {
            adj[min(e[0], e[1])].emplace(max(e[0], e[1]));
            ++degree[e[0]];
            ++degree[e[1]];
        }
        int result = numeric_limits<int>::max();
        for (int u = 1; u <= n; ++u) {
            for (const auto& v : adj[u]) {
                for (const auto& w : adj[u]) {
                    if (v < w && adj[v].count(w)) {
                        result = min(result, degree[u] + degree[v] + degree[w] - 6);
                    }
                }
            }
        }
        return (result != numeric_limits<int>::max()) ? result : -1;
    }
};
