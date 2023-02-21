// Time:  O(nlogn + m + qlogn)
// Space: O(n)

// segment tree
class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const auto& build = [&](const auto& i) {
            return vector<int>{nums1[i], nums1[i] ^ 1};
        };
        const auto& query = [](const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            return vector<int>{x[0] + y[0], x[1] + y[1]};
        };
        const auto& update = [](const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            return y == vector<int>{1, 0} ? vector<int>{x[1], x[0]} : vector<int>{x[0], x[1]};
        };
        SegmentTree<vector<int>> st(size(nums1), build, query, update);
        vector<long long> result;
        int64_t total = accumulate(cbegin(nums2), cend(nums2), 0LL);
        for (const auto& q : queries) {
            if (q[0] == 1) {
                st.update(q[1], q[2], vector<int>{1, 0});
            } else if (q[0] == 2) {
                total += static_cast<int64_t>(st.query(0, size(nums1) - 1)[0]) * q[1];
            } else if (q[0] == 3) {
                result.emplace_back(total);
            }
        }
        return result;
    }

private:
    template <typename T>
    class SegmentTree {
    public:
        explicit SegmentTree(
            int N,
            const function<T(const int&)>& build_fn,
            const function<T(const T&, const T&)>& query_fn,
            const function<T(const T&, const T&)>& update_fn)
        : base_(N),
            tree_(2 * N),
            lazy_(2 * N),
            build_fn_(build_fn),
            query_fn_(query_fn),
            update_fn_(update_fn) {
            H_ = 1;
            while ((1 << H_) < N) {
                ++H_;
            }
            for (int i = base_; i < base_ + N; ++i) {
                tree_[i] = build_fn_(i - base_);
            }
            for (int i = base_ - 1; i >= 1; --i) {
                tree_[i] = query_fn_(tree_[2 * i], tree_[2 * i + 1]);
            }
        }

        void update(int L, int R, const T& val) {
            L += base_;
            R += base_;
            int L0 = L, R0 = R;
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    apply(L++, val);
                }
                if ((R & 1) == 0) {
                    apply(R--, val);
                }
            }
            pull(L0);
            pull(R0);
        }

        T query(int L, int R) {
            T result{};
            if (L > R) {
                return result;
            }
            L += base_;
            R += base_;
            push(L);
            push(R);
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    result = query_fn_(result, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    result = query_fn_(result, tree_[R--]);
                }
            }
            return result;
        }

    private:
        void apply(int x, const T& val) {
            tree_[x] = update_fn_(tree_[x], val);
            if (x < base_) {
                lazy_[x] = update_fn_(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = query_fn_(tree_[x * 2], tree_[x * 2 + 1]);
                if (!empty(lazy_[x])) {
                    tree_[x] = update_fn_(tree_[x], lazy_[x]);
                }
            }
        }

        void push(int x) {
        for (int h = H_; h > 0; --h) {
            int y = x >> h;
            if (!empty(lazy_[y])) {
                    apply(y * 2, lazy_[y]);
                    apply(y * 2 + 1, lazy_[y]);
                    lazy_[y].clear();
                }
            }
        }

        int base_;
        int H_;
        vector<T> tree_;
        vector<T> lazy_;
        const function<T(const int&)> build_fn_;
        const function<T(const T&, const T&)> query_fn_;
        const function<T(const T&, const T&)> update_fn_;
    };
};
