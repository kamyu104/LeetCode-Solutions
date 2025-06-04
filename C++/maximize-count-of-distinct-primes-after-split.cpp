// Time:  O(r + nlogn + qlogn), r = max(nums)
// Space: O(r + n)

// number theory, bst, segment tree
vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
    vector<int> spf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return spf;
}

const int MAX_N = 1e5;
const auto& SPF = linear_sieve_of_eratosthenes(MAX_N);
class Solution {
public:
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> lookup;
        SegmentTree st(size(nums) - 1);
        const auto& add = [&](int i, int d) {
            const auto& x = nums[i];
            if (SPF[x] != x) {
                return;
            }
            if (d == 1) {
                lookup[x].emplace(i);
            }
            if (size(lookup[x]) == 1) {
                st.update(0, size(nums) - 2, d);
            } else if (i == *begin(lookup[x])) {
                st.update(i, *next(begin(lookup[x])) - 1, d);
            } else if (i == *rbegin(lookup[x])) {
                st.update(*next(rbegin(lookup[x])), i - 1, d);
            }
            if (d == -1) {
                lookup[x].erase(i);
            }
        };

        for (int i = 0; i < size(nums); ++i) {
            add(i, +1);
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const int idx = queries[i][0], x = queries[i][1];
            if (nums[idx] != x) {
                add(idx, -1);
                nums[idx] = x;
                add(idx, +1);
            }
            result[i] = st.tree[1];  // st.query(0, size(nums) - 2);
        }
        return result;
    }

private:
    class SegmentTree {
    public:
        explicit SegmentTree(int N)
         :  base_(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            lazy_(base_),
            tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2) {

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
                    left = max(left, tree[L++]);
                }
                if ((R & 1) == 0) {
                    right = max(tree[R--], right);
                }
            }
            return max(left, right);
        }

        vector<int> tree;

    private:
        void apply(int x, const int val) {
            tree[x] += val;
            if (x < base_) {
                lazy_[x] += val;
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                tree[x] = max(tree[x << 1], tree[(x << 1) + 1]);
                if (lazy_[x]) {
                    tree[x] += lazy_[x];
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
        vector<int> lazy_;
    };
};
