// Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
//        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
// Space: O(|E| + |V|) = O(|E|)

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }
        return dijkstra(adj, 0, n - 1);
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>>& adj,
                 int start,
                 int target) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int64_t> best = {{start, 0}};
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
        min_heap.emplace(0, start);
        vector<int> dp(size(adj));  // modified, add dp to keep number of ways
        dp[0] = 1;
        while (!empty(min_heap)) {
            const auto [curr, u] = min_heap.top(); min_heap.pop();
            if (best[u] < curr) {
                continue;
            }
            if (u == target) {  // modified, early return
                break;
            }
            for (const auto& [v, w] : adj[u]) {
                if ((best.count(v) && best[v] - curr <= w)) {
                    if (best[v] - curr == w) {  // modified, update number of ways in this minimal time
                        dp[v] = (static_cast<int64_t>(dp[v]) + dp[u]) % MOD;
                    }
                    continue;
                }
                dp[v] = dp[u];  // modified, init number of ways in this minimal time
                best[v] = curr + w;
                min_heap.emplace(curr + w, v);
            }
        }
        return dp.back();
    }
};
