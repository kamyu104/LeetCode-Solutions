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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderHelper(preorder,
                                     numeric_limits<int>::min(),
                                     numeric_limits<int>::max(),
                                     &index);
    }
    
private:
    TreeNode* bstFromPreorderHelper(const vector<int>& preorder,
                                    int left,
                                    int right,
                                    int *index) {

        if (*index == preorder.size() ||
            preorder[*index] < left ||
            preorder[*index] > right) {
            return nullptr;
        }
        
        auto root = new TreeNode(preorder[(*index)++]);
        root->left = bstFromPreorderHelper(preorder, left, root->val, index);
        root->right = bstFromPreorderHelper(preorder, root->val, right, index);
        return root;
    }
};
