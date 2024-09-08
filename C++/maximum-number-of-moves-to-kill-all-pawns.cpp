// Time:  O(p * n^2 + p^2 + p^2 * 2^p) = O(p^2 * 2^p)
// Space: O(p^2 + n^2 + p * 2^p) = O(p * 2^p)

// bfs, bitmasks, dp
class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        static const int N = 50;
        static const vector<pair<int, int>> DIRECTIONS = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
        static const int POS_INF = numeric_limits<int>::max();
        static const int NEG_INF = numeric_limits<int>::min();

        const auto& bfs = [](int r, int c) {
            vector<vector<int>> dist(N, vector<int>(N, POS_INF));
            dist[r][c] = 0;
            vector<pair<int, int>> q = {{r, c}};
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (const auto& [r, c] : q) {
                    for (const auto& [dr, dc] : DIRECTIONS) {
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < N && 0 <= nc && nc < N && dist[nr][nc] == POS_INF)) {
                            continue;
                        }
                        dist[nr][nc] = dist[r][c] + 1;
                        new_q.emplace_back(nr, nc);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };
    
        positions.emplace_back(vector<int>{kx, ky});
        vector<vector<int>> dist(size(positions), vector<int>(size(positions)));
        for (int i = 0; i < size(positions); ++i) {
            const auto& d = bfs(positions[i][0], positions[i][1]);
            for (int j = i + 1; j < size(positions); ++j) {
                dist[j][i] = dist[i][j] = d[positions[j][0]][positions[j][1]];
            }
        }
        vector<vector<int>> dp(1 << (size(positions) - 1));
        for (int mask = 1; mask < 1 << (size(positions) - 1); ++mask) {
            dp[mask].assign(size(positions) - 1, __builtin_popcount(mask) & 1 ? POS_INF : NEG_INF);
        }
        dp.back().assign(size(positions) - 1, 0);
        for (int mask = (1 << (size(positions) - 1)) - 1; mask >= 1; --mask) {
            const auto& turn = __builtin_popcount(mask) & 1;
            for (int i = 0; i < size(positions) - 1; ++i) {
                if (mask & (1 << i)) {
                    continue;
                }
                for (int j = 0; j < size(positions) - 1; ++j) {
                    if (j == i || (mask & (1 << j)) == 0) {
                        continue;
                    }
                    dp[mask][j] = turn ? min(dp[mask][j], dp[mask ^ (1 << i)][i] + dist[i][j])
                                       : max(dp[mask][j], dp[mask ^ (1 << i)][i] + dist[i][j]);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(positions) - 1; ++i) {
            result = max(result, dist.back()[i] + dp[1 << i][i]);
        }
        return result;
    }
};
