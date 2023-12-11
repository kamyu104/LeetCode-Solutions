// Time:  O(r + 2^n * n^2)
// Space: O(n^3)

// graph, bitmasks, Floyd-Warshall algorithm, backtracking
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        static const int INF = numeric_limits<int>::max();
        const auto& check = [&](int mask, const auto& dist) {
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                for (int j = i + 1; j < n; ++j) {
                    if ((mask & (1 << j)) == 0) {
                        continue;
                    }
                    if (dist[i][j] > maxDistance) {
                        return false;
                    }
                }
            }
            return true;
        };

        const auto& floydWarshall = [&](auto& dist, int k) {
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                         dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        int result = 0;
        const function<void (int, int, vector<vector<int>>)> backtracking = [&](int i, int mask, vector<vector<int>> dist) {
            if (i == n) {
                result += check(mask, dist);
                return;
            }
            for (int j = 0; j < 2; ++j) {
                vector<vector<int>> new_dist(dist);
                if (j) {
                    floydWarshall(new_dist, i);
                }
                backtracking(i + 1, mask | (j << i), new_dist);
            }
        };

        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int u = 0; u < n; ++u) {
            dist[u][u] = 0;
        }
        for (const auto& r : roads) {
            dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
            dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2]);
        }
        backtracking(0, 0, dist);
        return result;
    }
};

// Time:  O(r + 2^n * n^2)
// Space: O(n^3)
// bitmasks, Floyd-Warshall algorithm, backtracking
class Solution2 {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        static const int INF = numeric_limits<int>::max();
        const auto& check = [&](int mask, const auto& dist) {
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                for (int j = i + 1; j < n; ++j) {
                    if ((mask & (1 << j)) == 0) {
                        continue;
                    }
                    if (dist[i][j] > maxDistance) {
                        return false;
                    }
                }
            }
            return true;
        };

        const auto& floydWarshall = [&](int mask, auto dist) {
            for (int k = 0; k < n; ++k) {
                if ((mask & (1 << k)) == 0) {
                    continue;
                }
                for (int i = 0; i < n; ++i) {
                    if ((mask & (1 << i)) == 0) {  // optional, to speed up performance
                        continue;
                    }
                    for (int j = i + 1; j < n; ++j) {
                        if ((mask & (1 << j)) == 0) {  // optional, to speed up performance
                            continue;
                        }
                        if (dist[i][k] != INF && dist[k][j] != INF) {
                            dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            return check(mask, dist);
        };

        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int u = 0; u < n; ++u) {
            dist[u][u] = 0;
        }
        for (const auto& r : roads) {
            dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
            dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2]);
        }
        int result = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            result += floydWarshall(mask, dist);
        }
        return result;
    }
};
