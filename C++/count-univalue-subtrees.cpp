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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtrees(root, &count);
        return count;
    }
    
    bool isUnivalSubtrees(TreeNode* root, int *count) {
        if (root == nullptr) {
            return true;
        }
        bool left = isUnivalSubtrees(root->left, count);
        bool right = isUnivalSubtrees(root->right, count);
        if (isSame(root, root->left, left) &&
            isSame(root, root->right, right)) {
                ++(*count);
                return true;
        }
        return false;
    }
    
    bool isSame(TreeNode* root, TreeNode* child, bool is_uni) {
        return child == nullptr || (is_uni && root->val == child->val);
    }
};
