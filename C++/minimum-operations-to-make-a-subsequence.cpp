// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(target); ++i) {
            lookup[target[i]] = i;
        }
        vector<int> lis;
        for (const auto& x : arr) {
            if (!lookup.count(x)) {
                continue;
            }
            auto it = lower_bound(begin(lis), end(lis), lookup[x]);
            if (it == end(lis)) {
                lis.emplace_back(lookup[x]);
            } else {
                *it = lookup[x];
            }
        }
        return size(target) - size(lis);
    }
};

// Time:  O(nlogn)
// Space: O(n)
// segment tree solution
class Solution2 {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(target); ++i) {
            lookup[target[i]] = i;
        }
        SegmentTree st(size(lookup));
        for (const auto& x : arr) {
            if (!lookup.count(x)) {
                continue;
            }
            st.update(lookup[x], lookup[x], (lookup[x] >= 1) ? st.query(0, lookup[x] - 1) + 1 : 1);
        }
        return size(target) - ((size(lookup) >= 1) ? st.query(0, size(lookup) - 1) : 0);
    }

private:
    class SegmentTree {
    public:
        SegmentTree(int N)
            : N_(N),
              tree_(2 * N),
              lazy_(N)
        {
            H_ = 1;
            while ((1 << H_) < N) {
                ++H_;
            }
        }

        void update(int L, int R, int h) {
            L += N_; R += N_;
            int L0 = L, R0 = R;
            while (L <= R) {
                if ((L & 1) == 1) {
                    apply(L++, h);
                }
                if ((R & 1) == 0) {
                    apply(R--, h);
                }
                L >>= 1; R >>= 1;
            }
            pull(L0); pull(R0);
        }

        int query(int L, int R) {
            L += N_; R += N_;
            auto result = 0;
            push(L); push(R);
            while (L <= R) {
                if ((L & 1) == 1) {
                    result = max(result, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    result = max(result, tree_[R--]);
                }
                L >>= 1; R >>= 1;
            }
            return result;
        }

    private:
        int N_, H_;
        vector<int> tree_, lazy_;

        void apply(int x, int val) {
            tree_[x] = max(tree_[x], val);
            if (x < N_) {
                lazy_[x] = max(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = max(tree_[x * 2], tree_[x * 2 + 1]);
                tree_[x] = max(tree_[x], lazy_[x]);
            }
        }

        void push(int x) {
            for (int h = H_; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y] > 0) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }
    };
};
