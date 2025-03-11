// Time:  O(nlogn)
// Space: O(n)

// segment tree, binary search
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        SegmentTree st(baskets);
        for (const auto& x : fruits) {
            const int i = st.binary_search(x);
            if (i == -1) {
                ++result;
            } else {
                st.update(i, 0);
            }
        }
        return result;
    }

private:
    class SegmentTree {
     public:
        explicit SegmentTree(const vector<int>& nums)
          : tree(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 2) : 2),
            base(size(nums) > 1 ? 1 << (__lg(size(nums) - 1) + 1) : 1) {
            for (int i = base; i < size(tree); ++i) {
                tree[i] = nums[i - base];
            }
            for (int i = base - 1; i >= 1; --i) {
                tree[i] = max(tree[2 * i], tree[2 * i + 1]);
            }
        }

        void update(int i, int h) {
            int x = base + i;
            tree[x] = h;
            while (x > 1) {
                x /= 2;
                tree[x] = max(tree[x * 2], tree[x * 2 + 1]);
            }
        }

        int binary_search(int x) {
            if (tree[1] < x) {
                return -1;
            }
            int i = 1;
            while (!(i >= base)) {
                if (tree[2 * i] >= x) {
                    i = 2 * i;
                } else {
                    i = 2 * i + 1;
                }
            }
            return i - base;
        }

        vector<int> tree;
        int base;
    };
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        for (const auto& x : fruits) {
            int i = 0;
            for (; i < size(baskets); ++i) {
                if (baskets[i] >= x) {
                    baskets[i] = 0;
                    break;
                }
            }
            if (i == size(baskets)) {
                ++result;
            }
        }
        return result;
    }
};
