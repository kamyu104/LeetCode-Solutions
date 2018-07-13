// Time:  O(h)
// Space: O(1)

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *curr = root, *parent = nullptr;
        while (curr) {
            parent = curr;
            if (val <= curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        if (!parent) {
            root = new TreeNode(val);
        } else if (val <= parent->val) {
            parent->left = new TreeNode(val);
        } else {
            parent->right = new TreeNode(val);
        }
        return root;
    }
};


// Time:  O(h)
// Space: O(h)
class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
        } else {
            if (val <= root->val) {
                root->left = insertIntoBST(root->left, val);
            } else {
                root->right = insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};
