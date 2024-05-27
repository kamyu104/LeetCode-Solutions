// Time:  O(n + qlogn)
// Space: O(n)

// segment tree
class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;
        enum {L0R0, L1R0, L0R1, L1R1};

        const auto& build = [&](int i) {
            return vector<int64_t>{max(nums[i], 0), 0, 0, 0};
        };

        const auto& update = [] (const auto& c) {
            return c;
        };

        const auto& query = [&] (const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            if (empty(y)) {
                return x;
            }
            return vector<int64_t>{
                max({x[L0R1] + y[L1R0], x[L0R0] + y[L1R0], x[L0R1] + y[L0R0]}),
                max({x[L1R1] + y[L1R0], x[L1R0] + y[L1R0], x[L1R1] + y[L0R0]}),
                max({x[L0R1] + y[L1R1], x[L0R0] + y[L1R1], x[L0R1] + y[L0R1]}),
                max({x[L1R1] + y[L1R1], x[L1R0] + y[L1R1], x[L1R1] + y[L0R1]})
            };
        };

        SegmentTree<vector<int64_t>> st(size(nums), build, update, query);
        int result = 0;
        for (const auto& q : queries) {
            st.update(q[0], vector<int64_t>{max(q[1], 0), 0, 0, 0});
            result = (result + ranges::max(st.tree[1])) % MOD;
        }
        return result;
    }

private:
    // Template:
    // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/booking-concert-tickets-in-groups.cpp
    template <typename T>
    class SegmentTree {
     public:
        explicit SegmentTree(
            int N,
            const function<T(const int&)>& build_fn,
            const function<T(const T&)>& update_fn,
            const function<T(const T&, const T&)>& query_fn)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            build_fn_(build_fn),
            query_fn_(query_fn),
            update_fn_(update_fn) {

            for (int i = base; i < base + N; ++i) {
                tree[i] = build_fn_(i - base);
            }
            for (int i = base - 1; i >= 1; --i) {
                tree[i] = query_fn_(tree[i << 1], tree[(i << 1) + 1]);
            }
        }

        void update(int i, const T& h) {
            int x = base + i;
            tree[x] = update_fn_(h);
            while (x > 1) {
                x >>= 1;
                tree[x] = query_fn_(tree[x << 1], tree[(x << 1) + 1]);
            }
        }

        T query(int L, int R) {
            L += base;
            R += base;
            T left, right;
            for (; L <= R; L >>= 1, R >>= 1) {
                if (L & 1) {
                    left = query_fn_(left, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    right = query_fn_(tree[R], right);
                    --R;
                }
            }
            return query_fn_(left, right);
        }

        vector<T> tree;
        int base;

    private:
        const function<T(const int&)> build_fn_;
        const function<T(const T&)> update_fn_;
        const function<T(const T&, const T&)> query_fn_;
    };
};
