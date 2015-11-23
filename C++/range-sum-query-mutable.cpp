// Time:  ctor:   O(n),
//        update: O(h),
//        query:  O(h)
// Space: O(h), used by DFS

class NumArray {
public:
    NumArray(vector<int> &nums) : nums_ref_(nums) {
        root_ = buildHelper(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        if (nums_ref_[i] != val) {
            nums_ref_[i] = val;
            updateHelper(root_, i, val);
        }
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(root_, i, j);
    }

private:
    vector<int>& nums_ref_;

    class SegmentTreeNode {
    public:
        int start, end;
        int sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int i, int j, int s) : 
            start(i), end(j), sum(s),
            left(nullptr), right(nullptr) {
        }
    };

    SegmentTreeNode *root_;

    // Build segment tree.
    SegmentTreeNode *buildHelper(const vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        // The root's start and end is given by build method.
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 0);

        // If start equals to end, there will be no children for this node.
        if (start == end) {
            root->sum = nums[start];
            return root;
        }

        // Left child: start=numsleft, end=(numsleft + numsright) / 2.
        root->left = buildHelper(nums, start, (start + end) / 2);

        // Right child: start=(numsleft + numsright) / 2 + 1, end=numsright.
        root->right = buildHelper(nums, (start + end) / 2 + 1, end);

        // Update sum.
        root->sum = (root->left != nullptr ? root->left->sum : 0) +
                    (root->right != nullptr ? root->right->sum : 0);
        return root;
    }

    void updateHelper(SegmentTreeNode *root, int i, int val) {
        // Out of range.
        if (root == nullptr || root->start > i || root->end < i) {
            return;
        }

        // Change the node's value with [i] to the new given value.
        if (root->start == i && root->end == i) {
            root->sum = val;
            return;
        }

        updateHelper(root->left, i, val);
        updateHelper(root->right, i, val);

        // Update sum.
        root->sum =  (root->left != nullptr ? root->left->sum : 0) +
                     (root->right != nullptr ? root->right->sum : 0);
    }
    
    int sumRangeHelper(SegmentTreeNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end < start) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->sum;
        }

        return sumRangeHelper(root->left, start, end) +
               sumRangeHelper(root->right, start, end);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
