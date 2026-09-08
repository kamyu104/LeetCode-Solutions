// Time:  O(m * n * k)
// Space: O(m * n)

// dp
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        static const auto& INF = numeric_limits<int>::max();

        vector<vector<int>> dp(size(grid), vector<int>(size(grid[0]), INF));
        dp[0][0] = grid[0][0];
        for (int _ = 0; _ <= k; ++_) {
            auto new_dp = dp;
            for (int i = 0; i < size(grid); ++i) {
                int mn = INF;
                for (int j = 0; j < size(grid[0]); ++j) {
                    if (mn != INF) {
                        mn += grid[i][j];
                    }
                    mn = min(mn, dp[i][j]);
                    new_dp[i][j] = min(new_dp[i][j], mn);
                }
                mn = INF;
                for (int j = size(grid[0]) - 1; j >= 0; --j) {
                    if (mn != INF) {
                        mn += grid[i][j];
                    }
                    mn = min(mn, dp[i][j]);
                    new_dp[i][j] = min(new_dp[i][j], mn);
                }
            }
            for (int j = 0; j < size(grid[0]); ++j) {
                int mn = INF;
                for (int i = 0; i < size(grid); ++i) {
                    if (mn != INF) {
                        mn += grid[i][j];
                    }
                    mn = min(mn, dp[i][j]);
                    new_dp[i][j] = min(new_dp[i][j], mn);
                }
                mn = INF;
                for (int i = size(grid) - 1; i >= 0; --i) {
                   if (mn != INF) {
                        mn += grid[i][j];
                    }
                    mn = min(mn, dp[i][j]);
                    new_dp[i][j] = min(new_dp[i][j], mn);
                }
            }
            dp = move(new_dp);
        }
        return dp.back().back() != INF ? dp.back().back() : -1;
    }
};

// Time:  O(m * n * k * log(m * n * k))
// Space: O(m * n * k)
// dijkstra's algorithm
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        static const auto& INF = numeric_limits<int>::max();
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<vector<vector<int>>>> dist(size(grid), vector<vector<vector<int>>>(size(grid[0]), vector<vector<int>>(k + 1, vector<int>(4, INF))));
        priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<>> min_heap;
        min_heap.emplace(grid[0][0], 0, 0, -1, -1);
        while (!min_heap.empty()) {
            const auto [c, i, j, d, t] = min_heap.top(); min_heap.pop();
            if (d != -1 && c != dist[i][j][t][d]) {
                continue;
            }
            if (i == size(grid) - 1 && j == size(grid[0]) - 1) {
                return c;
            }
            for (int nd = 0; nd < size(DIRECTIONS); ++nd) {
                const auto& [di, dj] = DIRECTIONS[nd];
                const auto& ni = i + di, &nj = j + dj;
                if (!(0 <= ni && ni < size(grid) && 0 <= nj && nj < size(grid[0]))) {
                    continue;
                }
                const auto& nt = t + (d != nd);
                if (nt > k) {
                    continue;
                }
                if (c + grid[ni][nj] >= dist[ni][nj][nt][nd]) {
                    continue;
                }
                dist[ni][nj][nt][nd] = c + grid[ni][nj];
                min_heap.emplace(dist[ni][nj][nt][nd], ni, nj, nd, nt);
            }
        }
        return -1;
    }
};
