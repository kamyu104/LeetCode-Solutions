// Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
//        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

// dijkstra's algorithm
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        unordered_set<int> target(cbegin(marked), cend(marked));
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
        }
        const auto& dijkstra = [&](int start) {
            vector<int> best(size(adj), numeric_limits<int>::max());
            best[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                if (target.count(u)) {
                    return curr;
                }
                for (auto [v, w] : adj[u]) {
                    if (best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(curr + w, v);
                }
            }
            return -1;
        };

        return dijkstra(s);
    }
};
