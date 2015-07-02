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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        int rank = 0;
        while (!s.empty() || cur) {
            if (cur) {
                s.emplace(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                if (++rank == k) {
                    return cur->val;
                }
                cur = cur->right;
            }
        }

        return INT_MIN;
    }
};
