// Time:  O((n + k) * logn)
// Space: O(n + k)

// heap, sort, two pointers
class Solution {
private:
    struct TupleHash {
        template <typename... T>
        std::size_t operator()(const std::tuple<T...>& t) const {
            return apply([](const auto&... args) {
                std::size_t seed = 0;
                ((seed ^= std::hash<std::decay_t<decltype(args)>>{}(args) + 
                        0x9e3779b9 + (seed << 6) + (seed >> 2)), ...);
                return seed;
            }, t);
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> idxs(size(nums));
        iota(begin(idxs), end(idxs), 0);
        sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
            return nums[a] != nums[b] ? nums[a] < nums[b] : a < b;
        });
        const auto& nxt = [&](int left, int right, int i, int j) {
            for (; !(left <= idxs[i] && idxs[i] <= right); ++i);
            for (; !(left <= idxs[j] && idxs[j] <= right); --j);
            return tuple(i, j);
        };

        unordered_map<tuple<int, int>, tuple<int, int>, TupleHash> lookup;
        lookup[{0, size(idxs) - 1}] = {0, size(idxs) - 1};
        using P = pair<int, pair<int, int>>;
        priority_queue<P> max_heap;
        max_heap.push({nums[idxs[size(idxs) - 1]] - nums[idxs[0]], {0, size(idxs) - 1}});
        int64_t result = 0;
        while (k) {
            const auto [v, l_r] = max_heap.top();  max_heap.pop();
            const auto& [l, r] = l_r;
            const auto& [i, j] = lookup[{l, r}];
            const auto& nl = min(idxs[i], idxs[j]);
            const auto& nr = max(idxs[i], idxs[j]);
            const int64_t c = min((nl - l + 1) * (r - nr + 1), k);
            k -= c;
            result += c * v;
            if (nl + 1 <= r && !lookup.count({nl + 1, r})) {
                const auto& [ni, nj] = nxt(nl + 1, r, i, j);
                lookup[{nl + 1, r}] = {ni, nj};
                max_heap.push({nums[idxs[nj]] - nums[idxs[ni]], {nl + 1, r}});
            }
            if (l <= nr - 1 && !lookup.count({l, nr - 1})) {
                const auto& [ni, nj] = nxt(l, nr - 1, i, j);
                lookup[{l, nr - 1}] = {ni, nj};
                max_heap.push({nums[idxs[nj]] - nums[idxs[ni]], {l, nr - 1}});
            }
        }
        return result;
    }
};

// Time:  O((n + k) * logn)
// Space: O(nlogn)
// heap, rmq, sparse table
class Solution2 {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SparseTable rmq_min(nums, [](const auto& a, const auto& b) {
            return a < b ? a : b;
        });
        SparseTable rmq_max(nums, [](const auto& a, const auto& b) {
            return a > b ? a : b;
        });
        using P = pair<int, pair<int, int>>;
        vector<P> arr(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            arr[i] = {rmq_max.query(i, size(nums) - 1) - rmq_min.query(i, size(nums) - 1), {i, size(nums) - 1}};
        }
        priority_queue<P> max_heap(cbegin(arr), cend(arr));
        int64_t result = 0;
        for (int _ = 0; _ < k; ++_) {
            const auto [v, i_j] = max_heap.top(); max_heap.pop();
            const auto& [i, j] = i_j;
            result += v;
            if (i <= j - 1) {
                max_heap.push({rmq_max.query(i, j - 1) - rmq_min.query(i, j - 1), {i, j - 1}});
            }
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable {
    public:
        SparseTable(const vector<int>& arr, function<int (int, int)> fn)
         :  fn(fn) {  // Time: O(nlogn) * O(fn) = O(nlogn), Space: O(nlogn)
            const int n = size(arr);
            const int k = __lg(n);
            st.assign(k + 1, vector<int64_t>(n));
            st[0].assign(cbegin(arr), cend(arr));
            for (int i = 1; i <= k; ++i) {
                for (int j = 0; j + (1 << i) <= n; ++j) {
                    st[i][j] = fn(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                }
            }
         }

        int64_t query(int L, int R) const {
            const int i = __lg(R - L + 1);
            return fn(st[i][L], st[i][R - (1 << i) + 1]);  // Time: O(fn) = O(1)
        }
    
    private:
        vector<vector<int64_t>> st;
        const function<int (int, int)>& fn;
    };
};

// Time:  O((n + k) * logn)
// Space: O(n)
// heap, segment tree
const int NEG_INF = numeric_limits<int>::min();
const int POS_INF = numeric_limits<int>::max();
class Solution3 {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        SegmentTreeMin st_min(nums);
        SegmentTreeMax st_max(nums);
        using P = pair<int, pair<int, int>>;
        vector<P> arr(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            arr[i] = {st_max.query(i, size(nums) - 1) - st_min.query(i, size(nums) - 1), {i, size(nums) - 1}};
        }
        priority_queue<P> max_heap(cbegin(arr), cend(arr));
        int64_t result = 0;
        for (int _ = 0; _ < k; ++_) {
            const auto [v, i_j] = max_heap.top(); max_heap.pop();
            const auto& [i, j] = i_j;
            result += v;
            if (i <= j - 1) {
                max_heap.push({st_max.query(i, j - 1) - st_min.query(i, j - 1), {i, j - 1}});
            }
        }
        return result;
    }

private:
    class SegmentTreeMax {
    public:
        explicit SegmentTreeMax(const auto& nums)
         :  base_(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 1) : 1),
            tree(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 2) : 2, NEG_INF) {
            for (int i = base_; i < base_ + size(nums); ++i) {
                tree[i] = nums[i - base_];
            }
            for (int i = base_ - 1; i >= 1; --i) {
                tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
            }
        }

        int query(int L, int R) {
            if (L > R) {
                return NEG_INF;
            }
            L += base_;
            R += base_;
            int left = NEG_INF, right = NEG_INF;
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    left = max(left, tree[L++]);
                }
                if ((R & 1) == 0) {
                    right = max(tree[R--], right);
                }
            }
            return max(left, right);
        }

        vector<int> tree;
        int base_;
    };

    class SegmentTreeMin {
    public:
        explicit SegmentTreeMin(const auto& nums)
         :  base_(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 1) : 1),
            tree(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 2) : 2, POS_INF) {
            for (int i = base_; i < base_ + size(nums); ++i) {
                tree[i] = nums[i - base_];
            }
            for (int i = base_ - 1; i >= 1; --i) {
                tree[i] = min(tree[i << 1], tree[(i << 1) + 1]);
            }
        }

        int query(int L, int R) {
            if (L > R) {
                return POS_INF;
            }
            L += base_;
            R += base_;
            int left = POS_INF, right = POS_INF;
            for (; L <= R; L >>= 1, R >>= 1) {
                if ((L & 1) == 1) {
                    left = min(left, tree[L++]);
                }
                if ((R & 1) == 0) {
                    right = min(tree[R--], right);
                }
            }
            return min(left, right);
        }

        vector<int> tree;
        int base_;
    };
};
