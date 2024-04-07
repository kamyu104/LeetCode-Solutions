// Time:  O(n + e + q)
// Space: O(n)

// union find
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);
        for (const auto& e : edges) {
            uf.union_set(e[0], e[1], e[2]);
        }
        vector<int> result(size(query), -1);
        for (int i = 0; i < size(query); ++i) {
            if (uf.find_set(query[i][0]) != uf.find_set(query[i][1])) {
                continue;
            }
            result[i] = query[i][0] != query[i][1] ? uf.cost(query[i][0]) : 0;
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , w_(n, -1) {  // added
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y, int w) {  // modified
            x = find_set(x), y = find_set(y);
            if (x == y) {
                w_[x] &= w;  // added
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            w_[y] &= w_[x] & w;  // added
            return true;
        }

        int cost(int x) {  // added
            return w_[find_set(x)];
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> w_;
    };
};

