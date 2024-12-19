// Time:  O(n^2)
// Space: O(n)

// Bellman-Ford Algorithm
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        const auto& BellmanFord = [](auto& dist, const auto& pairs, const auto& rates) {
            for (int _ = 0; _ < size(pairs); ++_) {
                for (int i = 0; i < size(pairs); ++i) {
                    dist[pairs[i][1]] = max(dist[pairs[i][1]], dist[pairs[i][0]] * rates[i]);
                    dist[pairs[i][0]] = max(dist[pairs[i][0]], dist[pairs[i][1]] * (1.0 / rates[i]));
                }
            }
        };
        
        unordered_map<string, double> dist;
        dist[initialCurrency] = 1.0;
        BellmanFord(dist, pairs1, rates1);
        BellmanFord(dist, pairs2, rates2);
        return dist[initialCurrency];
    }
};

// Time:  O(n^2)
// Space: O(n)
// bfs
class Solution2 {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        const auto& find_adj = [](const auto& pairs, const auto& rates) {
            unordered_map<string, vector<pair<string, double>>> adj;
            for (int i = 0; i < size(pairs); ++i) {
                for (int i = 0; i < size(pairs); ++i) {
                    adj[pairs[i][0]].emplace_back(pairs[i][1], rates[i]);
                    adj[pairs[i][1]].emplace_back(pairs[i][0], 1 / rates[i]);
                }
            }
            return adj;
        };

        const auto& bfs = [](auto& dist, const auto& adj) {
            vector<string> q;
            for (const auto& [k, _] : adj) {
                q.emplace_back(k);
            }
            while (!empty(q)) {
                vector<string> new_q;
                for (const auto& u : q) {
                    if (empty(adj.at(u))) {
                        continue;
                    }
                    for (const auto& [v, w] : adj.at(u)) {
                        if (!(w * dist[u] > dist[v])) {
                            continue;
                        }
                        dist[v] = w * dist[u];
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
        };
        
        unordered_map<string, double> dist;
        dist[initialCurrency] = 1.0;
        const auto& adj1 = find_adj(pairs1, rates1);
        bfs(dist, adj1);  // Time: O(n)
        const auto& adj2 = find_adj(pairs2, rates2);
        bfs(dist, adj2);  // Time: O(n^2)
        return dist[initialCurrency];
    }
};
