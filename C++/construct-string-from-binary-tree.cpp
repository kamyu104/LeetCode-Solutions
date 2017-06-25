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
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        }

        auto s = to_string(t->val);

        if (t->left || t->right) {
            s += "(" + tree2str(t->left) + ")";
        }
        
        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }

        return s;
    }
};
