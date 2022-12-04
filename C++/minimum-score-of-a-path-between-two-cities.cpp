// Time:  O(n + m), m = len(roads)
// Space: O(n + m)

// bfs
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& r : roads) {
            adj[r[0] - 1].emplace_back(r[1] - 1, r[2]);
            adj[r[1] - 1].emplace_back(r[0] - 1, r[2]);
        }
        const auto& bfs = [&]() {
            vector<bool> lookup(size(adj));
            vector<int> q = {0};
            lookup[0] = true;
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& [v, w] : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return lookup;
        };

        const auto& lookup = bfs();
        int result = numeric_limits<int>::max();
        for (const auto& r : roads) {
            if (lookup[r[0] - 1]) {
                result = min(result, r[2]);
            }
        }
        return result;
    }
};
