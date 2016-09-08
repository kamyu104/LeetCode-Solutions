// Time:  O(n)
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
 
// Morris Traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (!curr->left) {
                if (prev && prev->val >= curr->val) {
                    return false;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = curr;
                    curr = curr->left;
                } else {
                    if (prev && prev->val >= curr->val) {
                        return false;
                    }
                    prev = curr;
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
                
        return true;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (last && last != root && last->val >= root->val) {
            return false;
        }

        last = root;

        if (!isValidBST(root->right)) {
            return false;
        }

        return true;
    }

private:
    TreeNode *last = nullptr;
};
