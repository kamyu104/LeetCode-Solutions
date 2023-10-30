// Time:  O(nlogn)
// Space: O(n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// bit, fenwick tree, ordered set, math
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
        ordered_set os;
        unordered_map<int, vector<int>> idxs;
        for (int i = size(nums) - 1; i >= 0; --i) {
            idxs[nums[i]].emplace_back(i);
        }
        for (const auto& [_, v] : idxs) {
            os.insert(v.back());
        }
        int result = 0;
        int accu = ((static_cast<int64_t>(size(nums)) * size(os)) % MOD) * size(os) % MOD;
        for (int i = 0; i < size(os); ++i) {
            accu = ((accu - (static_cast<int64_t>(2 * i + 1) * *os.find_by_order(i) % MOD)) % MOD + MOD) % MOD;
        }
        BIT bit(size(nums));
        for (const auto& x : os) {
            bit.add(x, x);
        }

        const auto& update = [&](int x, int accu, int d) {
            const int i = os.order_of_key(idxs[x].back());
            accu = ((accu + d * (static_cast<int64_t>(size(nums)) * (2 * static_cast<int>(size(os)) - 1)
                                 - static_cast<int64_t>(2 * i + 1) * idxs[x].back()
                                 - 2ll * (bit.query(size(nums) - 1) - bit.query(idxs[x].back())))) % MOD + MOD) % MOD;
            bit.add(idxs[x].back(), d * idxs[x].back());
            return accu;
        };

        for (const auto& x : nums) {
            result = (result + accu) % MOD;  // accu = sum(count(i, k) for k in range(i, len(nums)))
            accu = update(x, accu, -1);
            os.erase(idxs[x].back());
            idxs[x].pop_back();
            if (empty(idxs[x])) {
                continue;
            }
            os.insert(idxs[x].back());
            accu = update(x, accu, +1);
        }
        assert(accu == 0);
        return result;
    }

private:
    class BIT {
    public:
        BIT(int n) : bit_(n + 1) {  // 0-indexed
        }
        
        void add(int i, int val) {
            ++i;
            for (; i < size(bit_); i += lower_bit(i)) {
                bit_[i] = (bit_[i] + val) % MOD;
            }
        }

        int query(int i) const {
            ++i;
            int total = 0;
            for (; i > 0; i -= lower_bit(i)) {
                total = (total + bit_[i]) % MOD;
            }
            return total;
        }
    
    private:
        int lower_bit(int i) const {
            return i & -i;
        }
        
        vector<int> bit_;
        static const int MOD = 1e9 + 7;
    };
};

// Time:  O(nlogn)
// Space: O(n)
// dp, segment tree, math
class Solution2 {
public:
    int sumCounts(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        int result = 0, accu = 0;
        unordered_map<int, int> lookup;
        SegmentTree st(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            const int j = lookup.count(nums[i]) ? lookup[nums[i]] : -1;
            // sum(count(k, i)^2 for k in range(i+1)) - sum(count(k, i-1)^2 for k in range(i))
            // = sum(2*count(k, i-1)+1 for k in range(j+1, i+1))
            // = (i-j) + sum(2*count(k, i-1) for k in range(j+1, i+1))
            accu = (accu + ((i - j) + 2ll * st.query(j + 1, i))) % MOD;
            result = (result + accu) % MOD;
            st.update(j + 1, i, 1);  // count(k, i) = count(k, i-1)+(1 if k >= j+1 else 0) for k in range(i+1)
            lookup[nums[i]] = i;
        }
        return result;
    }

private:
    class SegmentTree {
    private:
        static const int MOD = 1e9 + 7;

    public:
        explicit SegmentTree(
            int N)
         :  base_(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            lazy_(base_),
            tree_(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            count_(size(tree_), 1) {

            for (int i = base_ - 1; i >= 1; --i) { // added
                count_[i] = count_[i << 1] + count_[(i << 1) + 1];
            }
        }

        void update(int L, int R, const int val) {
            L += base_;
            R += base_;
            // push(L);  // enable if range assignment
            // push(R);  // enable if range assignment
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

        int query(int L, int R) {
            if (L > R) {
                return 0;
            }
            L += base_;
            R += base_;
            push(L);
            push(R);
            int left = 0, right = 0;
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    left = (left + tree_[L++]) % MOD;
                }
                if ((R & 1) == 0) {
                    right = (tree_[R--] + right) % MOD;
                }
            }
            return (left + right) % MOD;
        }

    private:
        void apply(int x, const int val) {
            tree_[x] = (tree_[x] + static_cast<int64_t>(val) * count_[x]) % MOD;  // modified
            if (x < base_) {
                lazy_[x] = (lazy_[x] + val) % MOD;
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = (tree_[x << 1] + tree_[(x << 1) + 1]) % MOD;
                if (lazy_[x]) {
                    tree_[x] = (tree_[x] + static_cast<int64_t>(lazy_[x]) * count_[x]) % MOD;  // modified
                }
            }
        }

        void push(int x) {
            for (int h = __lg(x) - 1; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y]) {
                    apply(y << 1, lazy_[y]);
                    apply((y << 1) + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }

        int base_;
        vector<int> tree_;
        vector<int> lazy_;
        vector<int> count_;  // added
    };
};

// Time:  O(nlogn)
// Space: O(n)
// dp, segment tree, math
class Solution3 {
public:
    int sumCounts(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        const auto& sum = [&] (const auto& x, const auto& y) {
            return (x + y) % MOD;
        };

        int result = 0, accu = 0;
        unordered_map<int, int> lookup;
        SegmentTree<int> st(size(nums), sum, sum);
        for (int i = 0; i < size(nums); ++i) {
            const int j = lookup.count(nums[i]) ? lookup[nums[i]] : -1;
            // sum(count(k, i)^2 for k in range(i+1)) - sum(count(k, i-1)^2 for k in range(i))
            // = sum(2*count(k, i-1)+1 for k in range(j+1, i+1))
            // = (i-j) + sum(2*count(k, i-1) for k in range(j+1, i+1))
            accu = (accu + ((i - j) + 2ll * st.query(j + 1, i))) % MOD;
            result = (result + accu) % MOD;
            st.update(j + 1, i, 1);  // count(k, i) = count(k, i-1)+(1 if k >= j+1 else 0) for k in range(i+1)
            lookup[nums[i]] = i;
        }
        return result;
    }

private:
    template <typename T>
    class SegmentTree {
    private:
        static const int MOD = 1e9 + 7;

    public:
        explicit SegmentTree(
            int N,
            const function<T(const T&, const T&)>& query_fn,
            const function<T(const T&, const T&)>& update_fn)
         :  base_(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            lazy_(base_),
            tree_(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            count_(size(tree_), 1),
            query_fn_(query_fn),
            update_fn_(update_fn) {

            for (int i = base_ - 1; i >= 1; --i) { // added
                count_[i] = count_[i << 1] + count_[(i << 1) + 1];
            }
        }

        void update(int L, int R, const T& val) {
            L += base_;
            R += base_;
            // push(L);  // enable if range assignment
            // push(R);  // enable if range assignment
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
            if (L > R) {
                return T{};
            }
            L += base_;
            R += base_;
            push(L);
            push(R);
            T left{}, right{};
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    left = query_fn_(left, tree_[L++]);
                }
                if ((R & 1) == 0) {
                    right = query_fn_(tree_[R--], right);
                }
            }
            return query_fn_(left, right);
        }

    private:
        void apply(int x, const T val) {
            tree_[x] = update_fn_(tree_[x], (static_cast<int64_t>(val) * count_[x]) % MOD);  // modified
            if (x < base_) {
                lazy_[x] = update_fn_(lazy_[x], val);
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree_[x] = query_fn_(tree_[x << 1], tree_[(x << 1) + 1]);
                if (lazy_[x]) {
                    tree_[x] = update_fn_(tree_[x], (static_cast<int64_t>(lazy_[x]) * count_[x]) % MOD);  // modified
                }
            }
        }

        void push(int x) {
            for (int h = __lg(x) - 1; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y]) {
                    apply(y << 1, lazy_[y]);
                    apply((y << 1) + 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }

        int base_;
        vector<T> tree_;
        vector<T> lazy_;
        vector<T> count_;  // added
        const function<T(const T&, const T&)> query_fn_;
        const function<T(const T&, const T&)> update_fn_;
    };
};

// Time:  O(n^2)
// Space: O(n)
// hash table
class Solution4 {
public:
    int sumCounts(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            unordered_set<int> lookup;
            for (int j = i; j >= 0; --j) {
                lookup.emplace(nums[j]);
                result = (result + (static_cast<int64_t>(size(lookup)) * size(lookup) % MOD)) % MOD;
            }
        }
        return result;
    }
};
