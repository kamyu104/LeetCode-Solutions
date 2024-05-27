// Time:  O(qlogq)
// Space: O(q)

// bst, bit, fenwick tree
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> bst;
        for (const auto& q: queries) {
            if (q[0] == 1) {
                bst.emplace(q[1]);
            }
        }
        unordered_map<int, int> val_to_idx;
        int i = 0;
        for (const auto& x : bst) {
            val_to_idx[x] = i++;
        }
        const auto& fn = [](const auto& a, const auto& b) {
            return max(a, b);
        };

        BIT<int64_t> bit(size(val_to_idx), 0, fn);
        for (auto it = begin(bst); it != end(bst); ++it) {
            bit.update(val_to_idx[*it], *it - (it != begin(bst) ? *prev(it) : 0));
        }
        vector<bool> result;
        for (int i = size(queries) - 1; i >= 0; --i) {
            auto it = bst.lower_bound(queries[i][1]);
            if (queries[i][0] == 1) {
                if (next(it) != end(bst)) {
                    bit.update(val_to_idx[*next(it)], *next(it) - (it != begin(bst) ? *prev(it) : 0));
                }
                bst.erase(it);
            } else {
                result.emplace_back(queries[i][1] -  (it != begin(bst) ? *prev(it) : 0) >= queries[i][2] ||
                                    (it != begin(bst) && bit.query(val_to_idx[*prev(it)]) >= queries[i][2]));
            }
        }
        reverse(begin(result), end(result));
        return result;
    }

private:
    template<typename T>
    class BIT {
    public:
        BIT(int n, T val, const function<T (T, T)> fn)
          : bit_(n + 1, val),
            fn_(fn) {  // 0-indexed
        }
        
        void update(int i, T val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] = fn_(bit_[i], val);
            }
        }

        T query(int i) const {
            ++i;
            auto total = bit_[0];
            for (; i > 0; i -= lower_bit(i)) {
                total = fn_(total, bit_[i]);
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<T> bit_;
        const function<T (T, T)> fn_;
    };
};

// Time:  O(qlogq)
// Space: O(q)
// bst, segment tree
class Solution2 {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> bst;
        for (const auto& q: queries) {
            if (q[0] == 1) {
                bst.emplace(q[1]);
            }
        }
        unordered_map<int, int> val_to_idx;
        int i = 0;
        for (const auto& x : bst) {
            val_to_idx[x] = i++;
        }
        SegmentTree st(size(val_to_idx));
        const auto& update = [&](const auto& x) {
            bst.emplace(x);
            auto it = bst.find(x);
            st.update(val_to_idx[x], x - (it != begin(bst) ? *prev(it) : 0));
            if (next(it) != end(bst)) {
                st.update(val_to_idx[*next(it)], *next(it) - x);
            }
        };

        vector<bool> result;
        bst.clear();
        for (int i = 0; i < size(queries); ++i) {
            if (queries[i][0] == 1) {
                update(queries[i][1]);
            } else {
                auto it = bst.lower_bound(queries[i][1]);
                result.emplace_back(queries[i][1] - (it != begin(bst) ? *prev(it) : 0) >= queries[i][2] ||
                                    (it != begin(bst) && st.query(0, val_to_idx[*prev(it)]) >= queries[i][2]));
            }
        }
        return result;
    }

private:
    class SegmentTree {
     public:
        explicit SegmentTree(int N)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {
        }

        void update(int i, const auto& h) {
            int x = base + i;
            tree[x] = h;
            while (x > 1) {
                x >>= 1;
                tree[x] = max(tree[x << 1], tree[(x << 1) + 1]);
            }
        }

        int64_t query(int L, int R) {
            L += base;
            R += base;
            int64_t result = 0;
            for (; L <= R; L >>= 1, R >>= 1) {
                if (L & 1) {
                    result = max(result, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    result = max(result, tree[R]);
                    --R;
                }
            }
            return result;
        }

        vector<int64_t> tree;
        const int base;
    };
};
