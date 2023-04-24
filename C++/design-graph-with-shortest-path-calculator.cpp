// Time:  ctor:         O(|V| + |E|)
//        addEdge:      O(1)
//        shortestPath: O((|E| + |V|) * log|V|) = O(|E| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

// dijkstra's algorithm
class Graph {
public:
    Graph(int n, vector<vector<int>>& edges) : adj_(n) {
        for (const auto& edge : edges) {
            addEdge(edge);
        } 
    }
    
    void addEdge(vector<int> edge) {
        adj_[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        const auto& dijkstra = [](const auto& adj, int start, int target) {
            static const int INF = numeric_limits<int>::max();

            vector<int> best(size(adj), INF);
            best[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                if (u == target) {
                    break;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!(w < best[v] - curr)) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(curr + w, v);
                }
            }
            return best[target] != INF ? best[target] : -1;
        };

        return dijkstra(adj_, node1, node2);
    }

private:
    vector<vector<pair<int, int>>> adj_;
};
