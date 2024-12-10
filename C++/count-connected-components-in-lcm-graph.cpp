// Time:  O(n + tlogt), t = threshold
// Space: O(t)

// union find, number theory
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

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        UnionFind uf(threshold);
        vector<int> lookup(threshold, -1);
        int result = size(nums);
        for (const auto& x : nums) {
            if (x - 1 >= threshold) {
                continue;
            }
            for (int i = x; i <= threshold; i += x) {
                if (lookup[i - 1] == -1) {
                    lookup[i - 1] = x - 1;
                    continue;
                }
                if (uf.union_set(lookup[i - 1], x - 1)) {
                    --result;
                }
                if (i == x) {
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(n + tlogt), t = threshold
// Space: O(t)
// union find, number theory
class Solution2 {
public:
    int countComponents(vector<int>& nums, int threshold) {
        UnionFind uf(threshold);
        for (const auto& x : nums) {
            if (x - 1 >= threshold) {
                continue;
            }
            for (int i = x + x; i <= threshold; i += x) {
                uf.union_set(i - 1, x - 1);
            }
        }
        int result = 0;
        for (const auto& x : nums) {
            if (x - 1 >= threshold || uf.find_set(x - 1) == x - 1) {
                ++result;
            }
        }
        return result;
    }
};
