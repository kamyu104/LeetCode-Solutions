// Time Complexity: O(n)
// Space Complexity: O(logn)

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
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            pathSumImpl(root, sum);
            return ans;
        }
    private:
        vector<int> v;
        vector<vector<int> > ans;

        void pathSumImpl(TreeNode *root, int sum) {
            if(!root) {
                return;
            }

            v.push_back(root->val);

            if(!root->left && !root->right && root->val == sum) {
                ans.push_back(v);
            }

            pathSumImpl(root->left, sum - root->val);
            pathSumImpl(root->right, sum - root->val);

            v.pop_back(); // restore
        }
};
