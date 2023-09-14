// Time:  O(max(x^2 * y)) = O(n^3), n = len(grid)*len(grid[0]), y = len(zero), x = n-y
// Space: O(max(x^2)) = O(n^2)

// weighted bipartite matching solution
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        const auto& dist = [](const auto& a, const auto& b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };

        vector<pair<int, int>> src, dst;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j] - 1 >= 0) {
                    for (int _ = 0; _ < grid[i][j] - 1; ++_) {
                        src.emplace_back(i, j);
                    }
                } else {
                    dst.emplace_back(i, j);
                }
            }
        }
        vector<vector<int>> adj(size(src), vector<int>(size(dst)));
        for (int i = 0; i < size(src); ++i) {
            for (int j = 0; j < size(dst); ++j) {
                adj[i][j] = dist(src[i], dst[j]);
            }
        }
        return hungarian(adj).first;
    }

private:
    // Template modified from:
    // https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/WeightedMatching.h
    pair<int, vector<int>> hungarian(const vector<vector<int>> &a) {  // Time: O(n^2 * m), Space: O(n + m)
        if (a.empty()) return {0, {}};
        int n = size(a) + 1, m = size(a[0]) + 1;
        vector<int> u(n), v(m), p(m), ans(n - 1);
        for (int i = 1; i < n; ++i) {
            p[0] = i;
            int j0 = 0; // add "dummy" worker 0
            vector<int> dist(m, numeric_limits<int>::max()), pre(m, -1);
            vector<bool> done(m + 1);
            do { // dijkstra
                done[j0] = true;
                int i0 = p[j0], j1, delta = numeric_limits<int>::max();
                for (int j = 1; j < m; ++j) {
                    if (!done[j]) {
                        auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
                        if (dist[j] < delta) delta = dist[j], j1 = j;
                    }
                }
                for (int j = 0; j < m; ++j) {
                    if (done[j]) u[p[j]] += delta, v[j] -= delta;
                    else dist[j] -= delta;
                }
                j0 = j1;
            } while (p[j0]);
            while (j0) { // update alternating path
                int j1 = pre[j0];
                p[j0] = p[j1], j0 = j1;
            }
        }
        for (int j = 1; j < m; ++j) if (p[j]) ans[p[j] - 1] = j - 1;
        return {-v[0], ans}; // min cost
    }
};

// Time:  O(max(x^y)) = O((n/2)^(n/2))) = O(5^5), n = len(grid)*len(grid[0]), y = len(zero), x = n-y
// Space: O(y) = O(n) = O(9) = O(1)
// backtracking
class Solution2 {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        const auto& dist = [](const auto& a, const auto& b) {
            return abs(a.first - b.first) + abs(a.second - b.second);
        };

        vector<pair<int, int>> zero;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (grid[i][j] == 0) {
                    zero.emplace_back(i, j);
                }
            }
        }

        function<int (int)> backtracking = [&](int curr) {
            if (curr == size(zero)) {
                return 0;
            }
            int result = numeric_limits<int>::max();
            const auto& [i, j] = zero[curr];
            for (int ni = 0; ni < size(grid); ++ni) {
                for (int nj = 0; nj < size(grid[0]); ++nj) {
                    if (!(grid[ni][nj] >= 2)) {
                        continue;
                    }
                    --grid[ni][nj];
                    result = min(result, dist(pair(i, j), pair(ni, nj)) + backtracking(curr + 1));
                    ++grid[ni][nj];
                }
            }
            return result;
        };

        return backtracking(0);
    }
};
