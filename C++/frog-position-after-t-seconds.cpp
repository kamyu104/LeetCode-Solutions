// Time:  O(n)
// Space: O(n)

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> G;
        G[ROOT] = {};
        for (const auto& edge : edges) {
            G[edge[0]].emplace_back(edge[1]);
            G[edge[1]].emplace_back(edge[0]);
        }
        unordered_set<int> lookup;
        return dfs(G, ROOT, t, target, &lookup);
    }

private:
    double dfs(const unordered_map<int, vector<int>>& G,
               int node, int t, int target,
               unordered_set<int> *lookup) {
        if (!(G.at(node).size() - int(node != ROOT)) || !t) {
            return double(node == target);
        }
        lookup->emplace(node);
        double result = 0.0;
        for (const auto& child : G.at(node)) {
            if (lookup->count(child)) {
                continue;
            }
            result += dfs(G, child, t - 1, target, lookup);
        }
        return result / (G.at(node).size() - int(node != ROOT));
    }
    
    const int ROOT = 1;
};
