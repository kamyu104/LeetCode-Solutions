// Time:  O(n^2 * logn)
// Space: O(n^2)

// greedy, sort, union find with parity
class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        const auto& dist = [&](auto u, auto v) {
            return abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        };

        vector<tuple<int, int, int>> sorted_dists;
        for (int u = 0; u < size(points); ++u) {
            for (int v = u + 1; v < size(points); ++v) {
                sorted_dists.emplace_back(dist(u, v), u, v);
            }
        }
        sort(begin(sorted_dists), end(sorted_dists));
        UnionFind uf(size(points));
        for (const auto& [d, u, v] : sorted_dists) {
            if (!uf.union_set(u, v)) {
                return d;
            }
        }
        return 0;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
            : set_(n)
            , rank_(n)
            , parity_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
            vector<int> stk;
            while (set_[x] != x) {  // path compression
                stk.emplace_back(x);
                x = set_[x];
            }
            while (!empty(stk)) {
                const int y = stk.back(); stk.pop_back();
                parity_[y] ^= parity_[set_[y]];  // added
                set_[y] = x;
            }
            return x;
        }

        bool union_set(int x, int y) {
            int ox = x, oy = y;
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return parity_[ox] != parity_[oy]; // modified
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            set_[x] = y;  // Union by rank.
            parity_[x] = parity_[ox] ^ parity_[oy] ^ 1;
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> parity_;  // added
    };
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// greedy, sort, union find
class Solution2 {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        const auto& dist = [&](auto u, auto v) {
            return abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        };

        vector<tuple<int, int, int>> sorted_dists;
        for (int u = 0; u < size(points); ++u) {
            for (int v = u + 1; v < size(points); ++v) {
                sorted_dists.emplace_back(dist(u, v), u, v);
            }
        }
        sort(begin(sorted_dists), end(sorted_dists));
        vector<int> lookup(size(points), -1);
        UnionFind uf(size(points));
        for (const auto& [d, u, v] : sorted_dists) {
            if (uf.find_set(u) == uf.find_set(v)) {
                return d;
            }
            if (lookup[u] != -1) {
                uf.union_set(lookup[u], v);
            } else {
                lookup[u] = v;
            }
            if (lookup[v] != -1) {
                uf.union_set(lookup[v], u);
            } else {
                lookup[v] = u;
            }
        }
        return 0;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
            : set_(n)
            , rank_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
            vector<int> stk;
            while (set_[x] != x) {  // path compression
                stk.emplace_back(x);
                x = set_[x];
            }
            while (!empty(stk)) {
                const int y = stk.back(); stk.pop_back();
                set_[y] = x;
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
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            set_[x] = y;  // Union by rank.
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};

// Time:  O(n^2 * logn)
// Space: O(n^2)
// binary search, bfs, coordinate compression
class Solution3 {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        static const int INF = numeric_limits<int>::max();

        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& dist = [&](auto u, auto v) {
            return abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        };

        const auto& is_bipartite = [&](auto d) {
            vector<int> lookup(size(points), -1);
            const auto& bfs = [&](auto u) {
                if (lookup[u] != -1) {
                    return true;
                }
                lookup[u] = 0;
                vector<int> q = {u};
                while (!empty(q)) {
                    vector<int> new_q;
                    for (const auto& u : q) {
                        for (int v = 0; v < size(points); ++v) {
                            if (!(v != u && dist(v, u) < d)) {
                                continue;
                            }
                            if (lookup[v] != -1) {
                                if (lookup[v] != lookup[u] ^ 1) {
                                    return false;
                                }
                                continue;
                            }
                            lookup[v] = lookup[u] ^ 1;
                            new_q.emplace_back(v);
                        }
                    }
                    q = move(new_q);
                }
                return true;
            };

            for (int u = 0; u < size(points); ++u) {
                if (!bfs(u)) {
                    return false;
                }
            }
            return true;
        };

        vector<int> sorted_dists;
        for (int u = 0; u < size(points); ++u) {
            for (int v = u + 1; v < size(points); ++v) {
                sorted_dists.emplace_back(dist(u, v));
            }
        }
        sorted_dists.emplace_back(INF);
        sort(begin(sorted_dists), end(sorted_dists));
        auto it = unique(begin(sorted_dists), end(sorted_dists));
        sorted_dists.erase(it, end(sorted_dists));
        int left = 0, right = size(sorted_dists) - 1;
        const auto& result = binary_search_right(left, right, [&](auto i) { return is_bipartite(sorted_dists[i]); });
        return sorted_dists[result] != INF ? sorted_dists[result] : 0;
    }
};

// Time:  O(n^2 * logr)
// Space: O(n)
// binary search, bfs
class Solution4 {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        const auto& binary_search_right = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        const auto& dist = [&](auto u, auto v) {
            return abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        };

        const auto& is_bipartite = [&](auto d) {
            vector<int> lookup(size(points), -1);
            const auto& bfs = [&](auto u) {
                if (lookup[u] != -1) {
                    return true;
                }
                lookup[u] = 0;
                vector<int> q = {u};
                while (!empty(q)) {
                    vector<int> new_q;
                    for (const auto& u : q) {
                        for (int v = 0; v < size(points); ++v) {
                            if (!(v != u && dist(v, u) < d)) {
                                continue;
                            }
                            if (lookup[v] != -1) {
                                if (lookup[v] != lookup[u] ^ 1) {
                                    return false;
                                }
                                continue;
                            }
                            lookup[v] = lookup[u] ^ 1;
                            new_q.emplace_back(v);
                        }
                    }
                    q = move(new_q);
                }
                return true;
            };

            for (int u = 0; u < size(points); ++u) {
                if (!bfs(u)) {
                    return false;
                }
            }
            return true;
        };

        int mx = 0;
        for (int u = 0; u < size(points); ++u) {
            for (int v = u + 1; v < size(points); ++v) {
                mx = max(mx, dist(u, v));
            }
        }
        int left = 0, right = mx + 1;
        const auto& result = binary_search_right(left, right, is_bipartite);
        return result != mx + 1 ? result : 0;
    }
};
