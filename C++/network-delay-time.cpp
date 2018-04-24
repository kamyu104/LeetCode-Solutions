// Time:  O((|E| + |V|) * log|V|)
// Space: O(|E| + |V|)

// Dijkstra's algorithm
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        using P = pair<int, int>;
        vector<vector<P>> adj(N);
        for (const auto& time : times) {
            int u, v, w;
            tie(u, v, w) = make_tuple(time[0] - 1, time[1] - 1, time[2]);
            adj[u].emplace_back(v, w);
        }

        int result = 0;
        unordered_set<int> lookup;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        min_heap.emplace(0, K - 1);
        while (!min_heap.empty() && lookup.size() != N) {
            int u;
            tie(result, u) = min_heap.top(); min_heap.pop();
            lookup.emplace(u);
            for (const auto& kvp : adj[u]) {
                int v, w;
                tie(v, w) = kvp;
                if (lookup.count(v)) continue;
                min_heap.emplace(result + w, v);
            }
        }
        return lookup.size() == N ? result : -1;
    }
};
