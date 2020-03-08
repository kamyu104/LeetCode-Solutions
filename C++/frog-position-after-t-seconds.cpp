// Time:  O(n)
// Space: O(n)

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[1] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        return dfs(G, target, t, 1, 0);
    }

private:
    double dfs(const unordered_map<int, vector<int>>& G,
               int target, int t, int node, int parent) {
        if (!(G.at(node).size() - int(parent != 0)) || !t) {
            return (node == target);
        }
        double result = 0.0;
        for (const auto& child : G.at(node)) {
            if (child == parent) {
                continue;
            }
            result += dfs(G, target, t - 1, child, node);
        }
        return result / (G.at(node).size() - int(parent != 0));
    }
};
