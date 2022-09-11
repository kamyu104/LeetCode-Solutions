// Time:  O(nlogn)
// Space: O(n)

// segment tree with coordinate compression
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        unordered_set<int> nums_set;
        for (const auto& x : nums) {
            nums_set.emplace(x - 1);
        }
        vector<int> sorted_nums(cbegin(nums_set), cend(nums_set));
        sort(begin(sorted_nums), end(sorted_nums));
        unordered_map<int, int> num_to_idx;
        for (int i = 0; i < size(sorted_nums); ++i) {
            num_to_idx[sorted_nums[i]] = i;
        }
        SegmentTree st(size(num_to_idx));
        for (auto x : nums) {
            --x;
            const int i = distance(cbegin(sorted_nums), lower_bound(cbegin(sorted_nums), cend(sorted_nums), x - k));
            st.update(num_to_idx[x], st.query(i, num_to_idx[x] - 1) + 1);
        }
        return st.tree[1];  // st.query(0, size(num_to_idx) - 1)
    }

private:
    class SegmentTree {
     public:
        explicit SegmentTree(int N)
          : tree(N > 1 ? 1 << (__lg(N - 1) + 2) : 2),
            base(N > 1 ? 1 << (__lg(N - 1) + 1) : 1) {

        }

        void update(int i, int h) {
            int x = base + i;
            tree[x] = h;
            while (x > 1) {
                x /= 2;
                tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        int query(int L, int R) {
            if (L > R) {
                return 0;
            }
            L += base;
            R += base;
            int result = 0;
            for (; L <= R; L /= 2, R /= 2) {
                if (L & 1) {
                    result = max(result, tree[L]);
                    ++L;
                }
                if ((R & 1) == 0) {
                    result = max(tree[R], result);
                    --R;
                }
            }
            return result;
        }

        vector<int> tree;
        int base;
    };
};
