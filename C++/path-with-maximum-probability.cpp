// Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|) by using binary heap,
//        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }
        priority_queue<pair<double, int>> max_heap;
        max_heap.emplace(1.0, start);
        unordered_map<int, double> result;
        unordered_set<int> lookup;
        while (!max_heap.empty() && lookup.size() != adj.size()) {
            const auto [curr, u] = max_heap.top(); max_heap.pop();
            if (lookup.count(u)) {
                continue;
            }
            lookup.emplace(u);
            for (const auto& [v, w] : adj[u]) {
                if (lookup.count(v)) {
                    continue;
                }
                if (result.count(v) && result[v] >= curr * w) {
                    continue;
                }
                result[v] = curr * w;
                max_heap.emplace(result[v], v);
            }
        }
        return result[end];
    }
};
