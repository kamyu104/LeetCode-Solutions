// Time:  O(n^2 * logn)
// Space: O(n^2)

// bfs, dijkstra's algorithm
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const auto& bfs = [&]() {
            vector<vector<int>> dist(size(grid), vector<int>(size(grid[0]), -1));
            vector<pair<int, int>> q;
            for (int r = 0; r < size(grid); ++r) {
                for (int c = 0; c < size(grid[0]); ++c) {
                    if (grid[r][c]) {
                        dist[r][c] = 0;
                        q.emplace_back(r, c);
                    }
                }
            }
            int d = 0;
            for (int d = 0; !empty(q); ++d) {
                vector<pair<int, int>> new_q;
                for (const auto& [r, c] : q) {
                    for (const auto& [dr, dc] : DIRECTIONS) {
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && dist[nr][nc] == -1)) {
                            continue;
                        }
                        dist[nr][nc] = d + 1;
                        new_q.emplace_back(nr, nc);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };

        auto dist = bfs();
        const auto& dijkstra = [&](const auto& start, const auto& target) {
            priority_queue<pair<int, pair<int, int>>> max_heap;
            max_heap.emplace(dist[start.first][start.second], start);
            dist[start.first][start.second] = -1;
            while (!empty(max_heap)) {
                auto [curr, u] = max_heap.top(); max_heap.pop();
                if (u == target) {
                    return curr;
                }
                for (const auto& [dr, dc] : DIRECTIONS) {
                    const int nr = u.first + dr, nc = u.second + dc;
                    if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && dist[nr][nc] != -1)) {
                        continue;
                    }
                    max_heap.emplace(min(curr, dist[nr][nc]), pair(nr, nc));
                    dist[nr][nc] = -1;
                }
            }
            return -1;
        };

        return dijkstra(pair(0, 0), pair(static_cast<int>(size(dist) - 1), static_cast<int>(size(dist[0]) - 1)));
    }
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// bfs, binary search
class Solution2 {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const auto& bfs = [&]() {
            vector<vector<int>> dist(size(grid), vector<int>(size(grid[0]), -1));
            vector<pair<int, int>> q;
            for (int r = 0; r < size(grid); ++r) {
                for (int c = 0; c < size(grid[0]); ++c) {
                    if (grid[r][c]) {
                        dist[r][c] = 0;
                        q.emplace_back(r, c);
                    }
                }
            }
            int d = 0;
            for (int d = 0; !empty(q); ++d) {
                vector<pair<int, int>> new_q;
                for (const auto& [r, c] : q) {
                    for (const auto& [dr, dc] : DIRECTIONS) {
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && dist[nr][nc] == -1)) {
                            continue;
                        }
                        dist[nr][nc] = d + 1;
                        new_q.emplace_back(nr, nc);
                    }
                }
                q = move(new_q);
            }
            return dist;
        };

        const auto& dist = bfs();
        const auto& check = [&](int x) {
            vector<vector<int>> lookup(size(dist), vector<int>(size(dist[0])));
            vector<pair<int, int>> q = {{0, 0}};
            lookup[0][0] = 1;
            while (!empty(q)) {
                vector<pair<int, int>> new_q;
                for (const auto& [r, c] : q) {
                    for (const auto& [dr, dc] : DIRECTIONS) {
                        const int nr = r + dr, nc = c + dc;
                        if (!(0 <= nr && nr < size(dist) && 0 <= nc && nc < size(dist[0]) && dist[nr][nc] >= x && !lookup[nr][nc])) {
                            continue;
                        }
                        lookup[nr][nc] = 1;
                        new_q.emplace_back(nr, nc);
                    }
                }
                q = move(new_q);
            }
            return lookup.back().back();
        };

        int left = 0, right = dist[0][0];
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
