// Time:  O(n)
// Space: O(n)

// union find
class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        UnionFind uf(size(points));
        vector<unordered_map<int, int>> lookup(2);
        for (int i = 0; i < size(points); ++i) {
            for (int j = 0; j < size(lookup); ++j) {
                if (lookup[j].count(points[i][j])) {
                    uf.union_set(i, lookup[j][points[i][j]]);
                } else {
                    lookup[j][points[i][j]] = i;
                }
            }
        }
        vector<int> top(2);
        for (int i = 0; i < size(points); ++i) {
            if (uf.find_set(i) != i) {
                continue;
            }
            for (int j = 0, s = uf.total(i); j < size(top); ++j) {
                if (s > top[j]) {
                    swap(top[j], s);
                }
            }
        }
        return accumulate(cbegin(top), cend(top), 0) + 1;
     }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , size_(n, 1)  {
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
            } else if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            set_[x] = y;  // Union by rank.
            size_[y] += size_[x];
            return true;
        }

        int64_t total(int x) {
            return size_[find_set(x)];
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int64_t> size_;
    };
};
