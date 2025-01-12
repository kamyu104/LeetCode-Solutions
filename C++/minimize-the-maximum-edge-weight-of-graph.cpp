// Time:  O(nlogn + e)
// Space: O(n + e)

// dijkstra's algorithm
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        static const int INF = numeric_limits<int>::max();

        vector<unordered_map<int, int>> adj(n);
        const auto& dijkstra = [&]() {
            vector<int> best(size(adj), INF);
            best[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, 0);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr != best[u]) {
                    continue;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!(max(w, curr) < best[v])) {
                        continue;
                    }
                    best[v] = max(w, curr);
                    min_heap.emplace(best[v], v);
                }
            }
            const int result = ranges::max(best);
            return result != INF ? result : -1;
        };

        for (const auto& e : edges) {
            adj[e[1]][e[0]] = adj[e[1]].count(e[0]) ? min(adj[e[1]][e[0]], e[2]) : e[2];
        }
        return dijkstra();
    }
};

// Time:  O(nlogn + e)
// Space: O(n + e)
// prim's algorithm
class Solution2 {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        static const int INF = numeric_limits<int>::max();

        vector<unordered_map<int, int>> adj(n);
        const auto& prim = [&]() {
            vector<int> best(size(adj), INF);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, 0);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (best[u] != INF) {
                    continue;
                }
                best[u] = curr;
                for (const auto& [v, w] : adj[u]) {
                    if (best[v] != INF) {
                        continue;
                    }
                    min_heap.emplace(w, v);
                }
            }
            const int result = ranges::max(best);
            return result != INF ? result : -1;
        };

        for (const auto& e : edges) {
            adj[e[1]][e[0]] = adj[e[1]].count(e[0]) ? min(adj[e[1]][e[0]], e[2]) : e[2];
        }
        return prim();
    }
};

// Time:  O(nlogw + e)
// Space: O(n + e)
// binary search, bfs
class Solution3 {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        static const int INF = numeric_limits<int>::max();

        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<unordered_map<int, int>> adj(n);
        const auto& check = [&](const auto& x) {
            int cnt = size(adj);
            vector<bool> lookup(size(adj));
            lookup[0] = true;
            --cnt;
            vector<int> q = {0};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& [v, w] : adj[u]) {
                        if (w > x || lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        --cnt;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return cnt == 0;
        };
    
        for (const auto& e : edges) {
            adj[e[1]][e[0]] = adj[e[1]].count(e[0]) ? min(adj[e[1]][e[0]], e[2]) : e[2];
        }
        const int left = ranges::min(edges, [](const auto& a, const auto& b) { return a[2] < b[2]; })[2];
        const int right = ranges::max(edges, [](const auto& a, const auto& b) { return a[2] < b[2]; })[2];
        const int result = binary_search(left, right, check);
        return result <= right ? result : -1;
    }
};
