// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        BSTIterator left(root, true), right(root, false);
        while (*left < *right) {
            if (*left + *right == k) {
                return true;
            } else if (*left + *right < k) {
                ++left;
            } else {
                ++right;
            }
        }
        return false;
    }

private:
    class BSTIterator {
    public:
        BSTIterator(TreeNode *root, bool forward) :
            node_(root),
            forward_(forward) {
            ++(*this);
        };

        int operator*() {
            return cur_; 
        }

        void operator++() {
            while (node_ || !s_.empty()) {
                if (node_) {
                    s_.emplace(node_);
                    node_ = forward_ ? node_->left : node_->right;
                } else {
                    node_ = s_.top();
                    s_.pop();
                    cur_ = node_->val;
                    node_ = forward_ ? node_->right : node_->left;
                    break;
                }
            }
        }

    private:
        TreeNode* node_;
        bool forward_;
        stack<TreeNode*> s_;
        int cur_;
    };
};
