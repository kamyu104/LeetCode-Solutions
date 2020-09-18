// Time:  O(1), amortized
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) : pos_(-1) {
        traverseLeft(root);
    }
    
    bool hasNext() {
        return pos_ + 1 != size(vals_) || !empty(stk_);
    }
    
    int next() {
        if (++pos_ == size(vals_)) {
            TreeNode *node = stk_.back(); stk_.pop_back();
            traverseLeft(node->right);
            vals_.emplace_back(node->val);
        }
        return vals_[pos_];
    }
    
    bool hasPrev() {
        return pos_ - 1 >= 0;
    }
    
    int prev() {
        return vals_[--pos_];
    }

private:
    void traverseLeft(TreeNode *node) {
        for (; node != nullptr; node = node->left) {
            stk_.emplace_back(node);
        }
    }
    
    vector<TreeNode *> stk_;
    vector<int> vals_;
    int pos_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
