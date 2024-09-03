// Time:  O(n^2 * max(n, r)), r = max(x for row in grid for x in row)
// Space: O(n * max(n, r))

// hungarian algorithm, weighted bipartite matching
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int mx = 0;
        for (const auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }
        vector<vector<int>> adj(size(grid), vector<int>(max(mx, static_cast<int>(size(grid)))));
        for (int i = 0; i < size(grid); ++i) {
            for (const auto& x : grid[i]) {
                adj[i][x - 1] = -x;
            }
        }
        return -hungarian(adj).first;
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

// Time:  O(r + (n * m) * 2^n), r = max(x for row in grid for x in row)
// Space: O(r + n * m + 2^n)
// dp, bitmasks
class Solution2 {
public:
    int maxScore(vector<vector<int>>& grid) {
        int mx = 0;
        for (const auto& row : grid) {
            mx = max(mx, ranges::max(row));
        }
        vector<unordered_set<int>> lookup(mx);
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup[grid[i][j] - 1].emplace(i);
            }
        }
        vector<int> dp(1 << size(grid), numeric_limits<int>::min());
        dp[0] = 0;
        for (int x = 0; x < mx; ++x) {
            if (empty(lookup[x])) {
                continue;
            }
            for (int mask = size(dp) - 1; mask >= 0; --mask) {
                for (const auto& i : lookup[x]) {
                    if (mask & (1 << i)) {
                        continue;
                    }
                    dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + (x + 1));
                }
            }
        }
        return ranges::max(dp);
    }
};
