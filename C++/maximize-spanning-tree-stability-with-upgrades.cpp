// Time:  O(n + eloge)
// Space: O(n)

// union find, kruskal's algorithm, mst, maximum spanning tree, greedy
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        UnionFind uf(n);
        int cnt = 0;
        int result = numeric_limits<int>::max();
        for (const auto& e : edges) {
            const auto& u = e[0], &v = e[1], &s = e[2], &m = e[3];
            if (!m) {
                continue;
            }
            if (!uf.union_set(u, v)) {
                return -1;
            }
            ++cnt;
            result = min(result, s);
        }
        sort(begin(edges), end(edges), [](const auto& a, const auto& b) {
            return a[2] > b[2];
        });
        for (const auto& e : edges) {
            const auto& u = e[0], &v = e[1], &s = e[2], &m = e[3];
            if (m) {
                continue;
            }
            if (!uf.union_set(u, v)) {
                continue;
            }
            ++cnt;
            if (cnt == (n - 1) - k) {
                result = min(result, s);
            } else if (cnt == n - 1) {
                result = min(result, 2 * s);
            }
        }
        return cnt == n - 1 ? result : -1;
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
