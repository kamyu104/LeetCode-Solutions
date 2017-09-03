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
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> bst;
        findSecondMinimumValueHelper(root, &bst);
        if (bst.size() < 2) {
            return -1;
        } 
        return *bst.rbegin();
    }

private:
    void findSecondMinimumValueHelper(TreeNode* root, set<int> *bst) {
        if (!root) {
            return;
        }
        bst->emplace(root->val);
        if (bst->size() > 2) {
            bst->erase(prev(bst->end()));
        }
        findSecondMinimumValueHelper(root->left, bst);
        findSecondMinimumValueHelper(root->right, bst);
    }
};
