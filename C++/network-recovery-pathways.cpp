// Time:  O((n + e) * logr), r = max(e[2] for e in edges)
// Space: O(n + e)

// binary search, topological sort, dp
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        static const auto INF = numeric_limits<int64_t>::max();

        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        vector<vector<pair<int, int>>> adj(size(online));
        for (const auto& e : edges) {
            const int u = e[0], v = e[1], c = e[2];
            adj[u].emplace_back(v, c);
        }
        const auto& topological_sort = [&]() {
            vector<int> in_degree(size(adj));
            for (int u = 0; u < size(adj); ++u) {
                for (const auto& [v, _] : adj[u]) {
                    ++in_degree[v];
                }
            }
            vector<int> q;
            for (int u = 0; u < size(adj); ++u) {
                if (!in_degree[u]) {
                    q.emplace_back(u);
                }
            }
            vector<int> result;
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    result.emplace_back(u);
                    for (const auto& [v, _] : adj[u]) {
                        --in_degree[v];
                        if (in_degree[v]) {
                            continue;
                        }
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        const auto& order = topological_sort();
        const auto& check = [&](int x) {
            vector<int64_t> dist(size(adj), INF);
            dist[0] = 0;
            for (const auto& u : order) {
                if (dist[u] == INF) {
                    continue;
                }
                for (const auto& [v, c] : adj[u]) {
                    if (!(c >= x && online[v])) {
                        continue;
                    }
                    dist[v] = min(dist[v], dist[u] + c);
                }
            }
            return dist.back() <= k;
        };

        int left = numeric_limits<int>::max(), right = 0;
        for (int u = 0; u < size(adj); ++u) {
            for (const auto& [_, c] : adj[u]) {
                left = min(left, c);
                right = max(right, c);
            }
        }
        const auto& result = binary_search_right(left, right, check);
        return result >= left ? result : -1;
    }
};
