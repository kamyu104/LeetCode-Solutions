// Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
//        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

// dijkstra's algorithm
class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj1(n), adj2(n);
        for (const auto& e : edges) {
            adj1[e[0]].emplace_back(e[1], e[2]);
            adj2[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& dist1 = dijkstra(adj1, src1);
        const auto& dist2 = dijkstra(adj1, src2);
        const auto& dist3 = dijkstra(adj2, dest);
        int64_t result = INF;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INF && dist2[i] != INF && dist3[i] != INF) {
                result = min(result, dist1[i] + dist2[i] + dist3[i]);
            }
        }
        return result != INF ? result : -1;
    }

private:
    vector<int64_t> dijkstra(const vector<vector<pair<int, int>>>& adj, int start) {
        vector<int64_t> best(size(adj), INF);
        best[start] = 0;
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
        min_heap.emplace(0, start);
        while (!empty(min_heap)) {
            const auto [curr, u] = min_heap.top(); min_heap.pop();
            if (best[u] < curr) {
                continue;
            }
            for (const auto& [v, w] : adj[u]) {
                if (best[v] - curr <= w) {
                    continue;
                }
                best[v] = curr + w;
                min_heap.emplace(curr + w, v);
            }
        }
        return best;
    }
    
    const int64_t INF = numeric_limits<int64_t>::max();
};
