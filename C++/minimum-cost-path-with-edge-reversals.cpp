// Time:  O(n + elogn)
// Space: O(n + e)

// dijkstra's algorithm
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], 2 * e[2]);
        }
        const auto& dijkstra = [&]() {
            vector<int> best(size(adj), numeric_limits<int>::max());
            best[0] = 0;
            using Data = pair<int, int>;
            priority_queue<Data, vector<Data>, greater<Data>> min_heap;
            min_heap.emplace(best[0], 0);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                if (u == size(adj) - 1) {
                    return curr;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!(best[v] > curr + w)) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return -1;
        };

        return dijkstra();
    }
};
