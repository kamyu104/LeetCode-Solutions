// Time:  O(n * k + q * k * logn)
// Space: O(n * k)

// segment tree
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        const auto& build = [&](int i) {
            const int x = nums[i] % k;
            vector<int> cnt(k + 1);
            ++cnt[x];
            cnt.back() = x;
            return cnt;
        };

        const auto& update = [&](const auto& c) {
            const int x = c % k;
            vector<int> cnt(k + 1);
            ++cnt[x];
            cnt.back() = x;
            return cnt;
        };

        const auto& query = [&](const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            if (empty(y)) {
                return x;
            }
            vector<int> cnt(x);
            for (int i = 0; i < k; ++i) {
                cnt[x.back() * i % k] += y[i];
            }
            cnt.back() = x.back() * y.back() % k;
            return cnt;
        };

        SegmentTree<vector<int>> st(size(nums), build, update, query);
        vector<int> result(size(queries));
        for (int idx = 0; idx < size(queries); ++idx) {
            const int i = queries[idx][0];
            const int v = queries[idx][1];
            const int s = queries[idx][2];
            const int x = queries[idx][3];
            st.update(i, v);
            result[idx] = st.query(s, size(nums) - 1)[x];
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
            const function<T(const int&)>& update_fn,
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

        void update(int i, int h) {
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
        const function<T(const int&)> update_fn_;
        const function<T(const T&, const T&)> query_fn_;
    };
};
