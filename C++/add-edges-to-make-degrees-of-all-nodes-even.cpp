// Time:  O(n)
// Space: O(n)

// graph
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0] - 1].emplace(e[1] - 1);
            adj[e[1] - 1].emplace(e[0] - 1);
        }
        vector<int> odds;
        for (int u = 0; u < n; ++u) {
            if (size(adj[u]) % 2) {
                odds.emplace_back(u);
            }
        }
        if (size(odds) == 0) {
            return true;
        }
        if (size(odds) == 2) {
            for (int u = 0; u < n; ++u) {
                if (!adj[u].count(odds[0]) && !adj[u].count(odds[1])) {
                    return true;
                }
            }
            return false;
        }
        if (size(odds) == 4) {
            return ((!adj[odds[1]].count(odds[0]) && !adj[odds[3]].count(odds[2])) ||
                    (!adj[odds[2]].count(odds[0]) && !adj[odds[3]].count(odds[1])) ||
                    (!adj[odds[3]].count(odds[0]) && !adj[odds[2]].count(odds[1])));
        }
        return false;
    }
};
