// Time:  O(n)
// Space: O(n)

// bfs, constructive algorithms
class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        const auto& bfs = [&](int u) {
            vector<int> dist(n);
            dist[u] = 1;
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (dist[v]) {
                            continue;
                        }
                        dist[v] = dist[u] + 1;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const int mn = min_element(cbegin(adj), cend(adj), [](const auto& a, const auto& b) {
            return size(a) < size(b);
        })->size();
        vector<int> corners;
        for (int u = 0; u < n; ++u) {
            if (size(adj[u]) == mn) {
                corners.emplace_back(u);
            }
        }
        const auto& dist1 = bfs(corners[0]);
        sort(begin(corners), end(corners), [&](const auto& a, const auto& b) {
            return dist1[a] < dist1[b];
        });
        const auto& dist2 = bfs(corners[1]);
        const int c = dist1[corners[1]];
        const int r = n / c;
        vector<vector<int>> result(r, vector<int>(c));
        for (int u = 0; u < n; ++u) {
            const int i = (dist1[u] + dist2[u] - (1 + c)) / 2;
            const int j = (dist1[u] - 1) - i;
            result[i][j] = u;
        }
        return result;
    }
};
