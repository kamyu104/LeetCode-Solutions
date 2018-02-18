// Time:  O(|E| + |V|log|V|)
// Space: O(|E| + |V|)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        using P = pair<int, int>;
        unordered_map<int, vector<P>> adj;
        for (const auto& flight : flights) {
            int u, v, w;
            tie(u, v, w) = make_tuple(flight[0], flight[1], flight[2]);
            adj[u].emplace_back(v, w);
        }
        
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, src, K + 1);
        while (!min_heap.empty()) {
            int result, u, k;
            tie(result, u, k) = min_heap.top(); min_heap.pop();
            if (u == dst) {
                return result;
            }
            if (k > 0) {
                for (const auto& kvp : adj[u]) {
                    int v, w;
                    tie(v, w) = kvp;
                    min_heap.emplace(result + w, v, k - 1);
                }
            }
        }
        return -1;
    }
};
