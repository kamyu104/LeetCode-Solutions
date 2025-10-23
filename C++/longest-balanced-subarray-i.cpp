// Time:  O(nlogn)
// Space: O(n)

// segment tree, binary search, prefix sum
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int n = size(nums) + 1;
        SegmentTree st(n);
        int result = 0;
        unordered_map<int, int> lookup;
        for (int i = 1, curr = 0; i <= size(nums); ++i) {
            const auto& d = nums[i - 1] & 1 ? +1 : -1;
            if (lookup.count(nums[i - 1])) {
                st.update(lookup[nums[i - 1]], n - 1, -d);
                curr -= d;
            }
            curr += d;
            lookup[nums[i - 1]] = i;
            st.update(lookup[nums[i - 1]], n - 1, +d);
            const auto& l = i - st.binary_search(curr);
            if (l > result) {
                result = l;
            }
        }
        return result;
    }

private:
    class SegmentTree {
    public:
        explicit SegmentTree(int N)
         :  base_(N > 1 ? 1 << (__lg(N - 1) + 1) : 1),
            lazy_(base_),
            min(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            max(N > 1 ? 1 << (__lg(N - 1) + 2) : 2) {

        }

        void update(int L, int R, const int val) {
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

        int binary_search(int x) {
            int i = 1;
            while (!(i >= base_)) {
                if (lazy_[i]) {
                    apply(i << 1, lazy_[i]);
                    apply((i << 1) | 1, lazy_[i]);
                    lazy_[i] = 0;
                }
                i <<= 1;
                if (!(min[i] <= x && x <= max[i])) {
                    i |= 1;
                }
            }
            return i - base_;
        }

        vector<int> min, max;

    private:
        void apply(int x, const int val) {
            min[x] += val;
            max[x] += val;
            if (x < base_) {
                lazy_[x] += val;
            }
        }

        void pull(int x) {
            while (x > 1) {
                x >>= 1;
                min[x] = min[x << 1] < min[(x << 1) | 1] ? min[x << 1] : min[(x << 1) | 1];
                max[x] = max[x << 1] > max[(x << 1) | 1] ? max[x << 1] : max[(x << 1) | 1];
                if (lazy_[x]) {
                    min[x] += lazy_[x];
                    max[x] += lazy_[x];
                }
            }
        }

        void push(int x) {
            for (int h = __lg(x) - 1; h > 0; --h) {
                int y = x >> h;
                if (lazy_[y]) {
                    apply(y << 1, lazy_[y]);
                    apply((y << 1) | 1, lazy_[y]);
                    lazy_[y] = 0;
                }
            }
        }

        int base_;
        vector<int> lazy_;
    };
};

// Time:  O(n^2)
// Space: O(n)
// brute force
class Solution2 {
public:
    int longestBalanced(vector<int>& nums) {
        int result = 0;
        for (int left = 0; left < size(nums); ++left) {
            unordered_set<int> lookup;
            for (int right = left, curr = 0; right < size(nums); ++right) {
                if (!lookup.count(nums[right])) {
                    lookup.emplace(nums[right]);
                    curr += nums[right] & 1 ? +1 : -1;
                }
                if (curr == 0) {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};
