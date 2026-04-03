// Time:  O(n + e)
// Space: O(n)

// union find
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        int result = 0;
        UnionFind uf(n);
        for (const auto& e : edges) {
            if (uf.union_set(e[0], e[1], e[2])) {
                ++result;
            }
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , parity_(n) {  // added
            iota(begin(set_), end(set_), 0);
        }

        int find_set(int x) {
            if (set_[x] != x) {
                const int root = find_set(set_[x]);
                parity_[x] ^= parity_[set_[x]];  // added
                set_[x] = root;
            }
            return set_[x];
        }

        bool union_set(int x, int y, int w) {
            const int x0 = x, y0 = y;
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return parity_[x0] ^ w ^ parity_[y0] == 0;  // modified
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            } else if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            set_[x] = y;  // Union by rank.
            parity_[x] = parity_[x0] ^ w ^ parity_[y0];  // added
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> parity_;  // added
    };
};
