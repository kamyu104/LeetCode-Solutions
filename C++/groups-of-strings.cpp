// Time:  O(26 * n)
// Space: O(26 * n)

// bitmasks, union find
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        UnionFind uf(size(words));
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(words); ++i) {
            const int mask = accumulate(cbegin(words[i]), cend(words[i]), 0, [](int total, int x) {
                return total | (1 << (x - 'a'));
            });
            if (!lookup.count(mask)) {
                lookup[mask] = i;
            }
            uf.union_set(i, lookup[mask]);
            for (int bit = 1; bit <= mask; bit <<= 1) {
                if (mask & bit) {
                    if (!lookup.count(mask ^ bit)) {
                        lookup[mask ^ bit] = i;
                    }
                    uf.union_set(i, lookup[mask ^ bit]);
                }
            }
        }
        return {uf.total(), uf.max_size()};
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , size_(n, 1)
         , total_(n) {
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
            size_[y] += size_[x];
            --total_;
            return true;
        }

        int max_size() {
            return *max_element(cbegin(size_), cend(size_));
        }

        int total() {
            return total_;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> size_;
        int total_;
    };
};
