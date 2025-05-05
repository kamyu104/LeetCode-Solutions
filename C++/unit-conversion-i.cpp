// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        static const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(size(conversions) + 1);
        for (const auto& c : conversions) {
            adj[c[0]].emplace_back(c[1], c[2]);
        }
        vector<int> result(size(adj));
        result[0] = 1;
        vector<int> q = {0};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& [v, w] : adj[u]) {
                    result[v] = (static_cast<int64_t>(result[u]) * w) % MOD;
                    new_q.emplace_back(v);
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
