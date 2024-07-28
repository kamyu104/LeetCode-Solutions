// Time:  O(n^2)
// Space: O(n)

// iterative dfs
class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        const auto& iter_dfs = [&]() {
            vector<char> lookup(size(circles));
            vector<char> dst(size(circles));
            vector<int> stk;
            for (int u = 0; u < size(circles); ++u) {
                const int x = circles[u][0], y = circles[u][1], r = circles[u][2];
                if (x - r <= 0 || y + r >= Y) {
                    lookup[u] = true;
                    stk.emplace_back(u);
                }
                if (x + r >= X || y - r <= 0) {
                    dst[u] = true;
                }
            }
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                if (dst[u]) {
                    return true;
                }
                const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
                for (int v = 0; v < size(circles); ++v) {
                    const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                    if (lookup[v] || !check(x1, y1, r1, x2, y2, r2)) {
                        continue;
                    }
                    lookup[v] = true;;
                    stk.emplace_back(v);
                }
            }
            return false;
        };

        return !iter_dfs();
    }
};

// Time:  O(n^2)
// Space: O(n)
// bfs
class Solution2 {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        const auto& bfs = [&]() {
            vector<char> lookup(size(circles));
            vector<char> dst(size(circles));
            vector<int> q;
            for (int u = 0; u < size(circles); ++u) {
                const int x = circles[u][0], y = circles[u][1], r = circles[u][2];
                if (x - r <= 0 || y + r >= Y) {
                    lookup[u] = true;
                    q.emplace_back(u);
                }
                if (x + r >= X || y - r <= 0) {
                    dst[u] = true;
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    if (dst[u]) {
                        return true;
                    }
                    const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
                    for (int v = 0; v < size(circles); ++v) {
                        const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                        if (lookup[v] || !check(x1, y1, r1, x2, y2, r2)) {
                            continue;
                        }
                        lookup[v] = true;;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return false;
        };

        return !bfs();
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// iterative dfs
class Solution3 {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        vector<vector<int>> adj(size(circles) + 2);
        const auto& iter_dfs = [&](int src, int dst) {
            vector<char> lookup(size(adj));
            lookup[src] = true;
            vector<int> stk = {src};
            while (!empty(stk)) {
                const int u = stk.back(); stk.pop_back();
                if (u == dst) {
                    return true;
                }
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    lookup[v] = true;
                    stk.emplace_back(v);
                }
            }
            return false;
        };

        for (int u = 0; u < size(circles); ++u) {
            const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
            if (x1 - r1 <= 0 || y1 + r1 >= Y) {
                adj[u].emplace_back(size(circles));
                adj[size(circles)].emplace_back(u);
            }
            if (x1 + r1 >= X || y1 - r1 <= 0) {
                adj[u].emplace_back(size(circles) + 1);
                adj[size(circles) + 1].emplace_back(u);
            }
            for (int v = 0; v < u; ++v) {
                const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                if (!check(x1, y1, r1, x2, y2, r2)) {
                    continue;
                }
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }
        return !iter_dfs(size(circles), size(circles) + 1);
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// bfs
class Solution4 {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        vector<vector<int>> adj(size(circles) + 2);
        const auto& bfs = [&](int src, int dst) {
            vector<char> lookup(size(adj));
            lookup[src] = true;
            vector<int> q = {src};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return lookup[dst];
        };

        for (int u = 0; u < size(circles); ++u) {
            const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
            if (x1 - r1 <= 0 || y1 + r1 >= Y) {
                adj[u].emplace_back(size(circles));
                adj[size(circles)].emplace_back(u);
            }
            if (x1 + r1 >= X || y1 - r1 <= 0) {
                adj[u].emplace_back(size(circles) + 1);
                adj[size(circles) + 1].emplace_back(u);
            }
            for (int v = 0; v < u; ++v) {
                const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                if (!check(x1, y1, r1, x2, y2, r2)) {
                    continue;
                }
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }
        return !bfs(size(circles), size(circles) + 1);
    }
};

// Time:  O(n^2)
// Space: O(n)
// union find
class Solution_TLE {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        const auto& check = [](int64_t x1, int64_t y1, int64_t r1, int64_t x2, int64_t y2, int64_t r2) {
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
        };

        vector<vector<int>> adj(size(circles) + 2);
        UnionFind uf(size(circles) + 2);
        for (int u = 0; u < size(circles); ++u) {
            const int x1 = circles[u][0], y1 = circles[u][1], r1 = circles[u][2];
            if (x1 - r1 <= 0 || y1 + r1 >= Y) {
                uf.union_set(u, size(circles));
            }
            if (x1 + r1 >= X || y1 - r1 <= 0) {
                uf.union_set(u, size(circles) + 1);
            }
            for (int v = 0; v < u; ++v) {
                const int x2 = circles[v][0], y2 = circles[v][1], r2 = circles[v][2];
                if (!check(x1, y1, r1, x2, y2, r2)) {
                    continue;
                }
                uf.union_set(u, v);
            }
        }
        return uf.find_set(size(circles)) != uf.find_set(size(circles) + 1);
    }

private:
class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n) { 
            iota(begin(set_), end(set_), 0);
        }

        int find_set(int x) {
            vector<int> stk;
            while (set_[x] != x) {  // path compression
                stk.emplace_back(x);
                x = set_[x];
            }
            return x;
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};
