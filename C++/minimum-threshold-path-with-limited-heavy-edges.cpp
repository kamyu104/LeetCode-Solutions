// Time:  O((n + e) * loge)
// Space: O(n + e)

// binary search, 0-1 bfs, deque
class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<vector<pair<int, int>>> adj(n);
        vector<int> weights = {0};
        const auto& check = [&](int i) {
            const auto& t = weights[i];
            vector<bool> lookup(n);
            deque<pair<int, int>> dq = {{source, 0}};
            while (!empty(dq)) {
                const auto [u, d] = dq.front(); dq.pop_front();
                if (lookup[u]) {
                    continue;
                }
                lookup[u] = true;
                if (u == target) {
                    return d <= k;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (w <= t) {
                        dq.emplace_front(v, d);
                    } else {
                        dq.emplace_back(v, d + 1);
                    }
                }
            }
            return false;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
            weights.emplace_back(e[2]);
        }
        ranges::sort(weights);
        weights.erase(unique(begin(weights), end(weights)), end(weights));
        const auto& i = binary_search(0, size(weights) - 1, check);
        return i < size(weights) ? weights[i] : -1;
    }
};
