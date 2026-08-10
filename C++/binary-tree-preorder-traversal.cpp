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
void traverse(TreeNode* root,vector<int> &temp){
    if(root==NULL){
            return;
        }
    temp.push_back(root->val);
    traverse(root->left,temp);
    traverse(root->right,temp);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root,ans);
        return ans;
    }
};
