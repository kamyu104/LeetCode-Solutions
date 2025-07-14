// Time:  O(n + eloge)
// Space: O(n)

// backward simulation, union find, sort
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(begin(edges), end(edges), [](const auto& a, const auto& b) {
            return a[2] < b[2];
        });
        int cnt = 0;
        UnionFind uf(n);
        for (const auto& e : edges) {
            if (!uf.union_set(e[0], e[1])) {
                continue;
            }
            if (++cnt == n - k) {
                return e[2];
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
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
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
