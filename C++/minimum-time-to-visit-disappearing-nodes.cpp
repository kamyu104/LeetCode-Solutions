// Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
//        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

// dijkstra's algorithm
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        static const int INF = numeric_limits<int>::max();
    
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& modified_dijkstra = [&](int start) {
            vector<int> best(n, -1);
            best[start] = 0;
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(best[start], start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                for (auto [v, w] : adj[u]) {
                    if (!(w < min(best[v] != -1 ? best[v] : INF, disappear[v]) - curr)) {  // modified
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v],  v);
                }
            }
            return best;
        };
    
        return modified_dijkstra(0);
    }
};
