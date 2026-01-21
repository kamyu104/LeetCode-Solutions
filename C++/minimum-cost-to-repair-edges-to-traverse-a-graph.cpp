// Time:  O((n + m) * logr)
// Space: O(n + m)

// binary search, bfs
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
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
        const auto& bfs = [&](int x) {
            vector<bool> lookup(n);
            lookup[0] = true;
            vector<int> q = {0};
            for (int d = 0; !empty(q); ++d) {
                if (d == k + 1) {
                    break;
                }
                vector<int> new_q;
                for (const auto& u : q) {
                    if (u == n - 1) {
                        return true;
                    }
                    for (const auto& [v, w] : adj[u]) {
                        if (w > x || lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return false;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& left = (*min_element(cbegin(edges), cend(edges), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        }))[2];
        const auto& right = (*max_element(cbegin(edges), cend(edges), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        }))[2];
        const auto& result = binary_search(left, right, bfs);
        return result != right + 1 ? result : -1;
    }
};
