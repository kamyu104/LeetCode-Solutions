// Time:  O(n)
// Space: O(1)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        MorrisTraversal(root);
    }

private:
    void MorrisTraversal(TreeNode *root) {
        if (!root) {
            return;
        }
        pair<TreeNode *, TreeNode *> broken;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                detect(prev, cur, &broken);
                prev = cur;
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    detect(prev, cur, &broken);
                    prev = cur;
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        swap(broken.first->val, broken.second->val);
    }

    void detect(TreeNode *prev, TreeNode *cur, pair<TreeNode *, TreeNode *> *broken) {
        if (prev && prev->val > cur->val) {
            if (!broken->first) { // Find the first broken node.
                broken->first = prev;
            }
            broken->second = cur;  // Find the last broken node.
        }
    }
};
