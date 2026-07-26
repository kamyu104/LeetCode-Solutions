// Time:  O(m * n * log(m * n))
// Space: O(m * n)

// dijkstra's algorithm
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        static const vector<tuple<int, int, int>> DIRECTIONS = {{1, 0, 1}, {1, 1, 0}, {0, 0, -1}, {0, -1, 0}};

        vector<vector<vector<int64_t>>> dist(2, vector<vector<int64_t>>(m, vector<int64_t>(n, numeric_limits<int64_t>::max())));
        const int np = 0, ni = 0, nj = 0;
        dist[np][ni][nj] = (ni + 1LL) * (nj + 1LL);
        priority_queue<tuple<int64_t, int, int, int>, vector<tuple<int64_t, int, int, int>>, greater<>> min_heap;
        min_heap.emplace(dist[np][ni][nj], np, ni, nj);
        while (!empty(min_heap)) {
            const auto [w, p, i, j] = min_heap.top(); min_heap.pop();
            if (w != dist[p][i][j]) {
                continue;
            }
            if (i == m - 1 && j == n - 1) {
                return w;
            }
            if (w + penalty[i][j] < dist[p ^ 1][i][j]) {
                dist[p ^ 1][i][j] = w + penalty[i][j];
                min_heap.emplace(dist[p ^ 1][i][j], p ^ 1, i, j);
            }
            for (const auto& [dp, di, dj]: DIRECTIONS) {
                const int np = p ^ 1, &ni = i + di, &nj = j + dj;
                if (!(0 <= ni && ni < m &&
                      0 <= nj && nj < n &&
                      w + (ni + 1LL) * (nj + 1LL) + (np != dp ? penalty[i][j] : 0) < dist[np][ni][nj])) {
                    continue;
                }
                dist[np][ni][nj] = w + (ni + 1LL) * (nj + 1LL) + (np != dp ? penalty[i][j] : 0);
                min_heap.emplace(dist[np][ni][nj], np, ni, nj);
            }
        }
        return -1;
    }
};
