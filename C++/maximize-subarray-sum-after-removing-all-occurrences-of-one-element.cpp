// Time:  O(n)
// Space: O(n)

// hash table, greedy, kadane's algorithm
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        int64_t curr = 0, mn = 0, mn0 = 0;
        unordered_map<int, int64_t> mn1;        
        for (const auto& x: nums) {
            curr += x;
            result = max(result, curr - mn);
            mn1[x] = min(mn1[x], mn0) + x;
            mn0 = min(mn0, curr);
            mn = min({mn, mn1[x], mn0});
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// hash table, greedy, kadane's algorithm
class Solution2 {
public:
    long long maxSubarraySum(vector<int>& nums) {
        int64_t result = numeric_limits<int64_t>::min();
        int64_t curr = 0, mn = 0, mn0 = 0;
        unordered_map<int, int64_t> mn1;        
        for (const auto& x: nums) {
            curr += x;
            result = max(result, curr - mn);
            if (x < 0) {
                mn1[x] = min(mn1[x], mn0) + x;
                mn = min(mn, mn1[x]);
            }
            mn0 = min(mn0, curr);
            mn = min(mn, mn0);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// segment tree
class Solution_TLE {
public:
    long long maxSubarraySum(vector<int>& nums) {
        enum {MAX, TOTAL, PREFIX, SUFFIX};

        const auto& build = [&](int i) {
            return vector<int64_t>(4, nums[i]);
        };

        const auto& update = [](const auto& c) {
            return c;
        };

        const auto& query = [&](const auto& x, const auto& y) {
            if (empty(x)) {
                return y;
            }
            if (empty(y)) {
                return x;
            }
            return vector<int64_t>{
                max({x[MAX], y[MAX], x[SUFFIX] + y[PREFIX]}),
                x[TOTAL] + y[TOTAL],
                max(x[PREFIX], x[TOTAL] + y[PREFIX]),
                max(y[SUFFIX], x[SUFFIX] + y[TOTAL])
            };
        };

        const int mx = ranges::max(nums);
        if (mx < 0) {
            return mx;
        }
        const int mn = ranges::min(nums);
        if (mn >= 0) {
            return accumulate(cbegin(nums), cend(nums), 0ll);
        }
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < size(nums); ++i) {
            groups[nums[i]].emplace_back(i);
        }
        SegmentTree<vector<int64_t>> st(size(nums), build, update, query);
        int64_t result = st.tree[1][0];  // st.query(0, size(nums) - 1)[0]
        for (const auto& [k, v] : groups) {
            vector<int64_t> arr;
            for (const auto& i : v) {
                st.update(i, arr);
            }
            result = max(result, st.tree[1][0]);  // st.query(0, size(nums) - 1)[0]
            arr.assign(4, k);
            for (const auto& i : v) {
                st.update(i, arr);
            }
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
