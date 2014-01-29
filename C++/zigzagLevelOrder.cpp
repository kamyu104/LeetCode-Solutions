// Time Complexity: O(n)
// Space Complexity: O(n)

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
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            bool isLeftToRight = true;
            vector<vector<int> > ans;
            queue<TreeNode *> q;
            TreeNode * n;
            vector<int> v;
            int size = 0;
            int cnt = 0;

            if(!root)
                return ans;

            q.push(root);
            size = 1;
            while(size) {
                n = q.front();
                v.push_back(n->val);

                if(n->left) {
                    q.push(n->left);
                    cnt++;
                }
                if(n->right) {
                    q.push(n->right);
                    cnt++;
                }

                q.pop();
                size--;
                if(size == 0) {
                    if(!isLeftToRight)
                        reverse(v.begin(), v.end());
                    isLeftToRight = !isLeftToRight;
                    size = cnt;
                    cnt = 0;
                    ans.push_back(v);
                    v.clear();
                }
            }
            return ans;
        }
};


