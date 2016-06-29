// Time:  ctor:   O(n),
//        update: O(logn),
//        query:  O(logn)
// Space: O(n)

// Segment Tree solution.
class NumArray {
public:
    NumArray(vector<int> &nums) : nums_(nums) {
        root_ = buildHelper(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        if (nums_[i] != val) {
            nums_[i] = val;
            updateHelper(root_, i, val);
        }
    }

    int sumRange(int i, int j) {
        return sumRangeHelper(root_, i, j);
    }

private:
    vector<int>& nums_;

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

// Time:  ctor:   O(n),
//        update: O(logn),
//        query:  O(logn)
// Space: O(n)
// Binary Indexed Tree (BIT) solution.
class NumArray2 {
public:
    NumArray(vector<int> &nums) : nums_(nums) {
        bit_ = vector<int>(nums_.size() + 1);
        for (int i = 1; i < bit_.size(); ++i) {
            bit_[i] = nums[i - 1] + bit_[i - 1];
        }
        for (int i = bit_.size() - 1; i >= 1; --i) {
            int last_i = i - (i & -i);
            bit_[i] -= bit_[last_i];
        }
    }

    void update(int i, int val) {
        if (val - nums_[i]) {
            add(i, val - nums_[i]);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) {
        int sum = sumRegion_bit(j);
        if (i > 0) {
            sum -= sumRegion_bit(i - 1);
        }
        return sum;
    }

private:
    vector<int> &nums_;
    vector<int> bit_;

    int sumRegion_bit(int i) {
        ++i;
        int sum = 0;
        for (; i > 0; i -= lower_bit(i)) {
            sum += bit_[i];
        }
        return sum;
    }

    void add(int i, int val) {
        ++i;
        for (; i <= nums_.size(); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }

    int lower_bit(int i) {
        return i & -i;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
