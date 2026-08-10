/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].emplace_back(nullptr);
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= i; j++) 
            {
                for (auto l : dp[j - 1]) 
                {
                    for (auto r : dp[i - j]) {
                        auto m = new TreeNode(j, l, r);
                        dp[i].emplace_back(m);
                    }
                }
            }
        }
        function<void(TreeNode*&, int)> replace = [&] (TreeNode *&p, int val) 
        {
            if (!p) return;
            p = new TreeNode(p->val + val, p->left, p->right);
            replace(p->left, val);
            replace(p->right, p->val);
        }; 
        for (auto &t : dp[n])
            replace(t, 0);
        return dp[n];
    }
};
