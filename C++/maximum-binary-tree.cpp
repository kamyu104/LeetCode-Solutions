// Time:  O(n)
// Space: O(n)

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // https://github.com/kamyu104/LintCode/blob/master/C++/max-tree.cpp
        vector<TreeNode *> nodeStack;
        for (int i = 0; i < nums.size(); ++i) {
            auto node = new TreeNode(nums[i]);
            while (!nodeStack.empty() && nums[i] > nodeStack.back()->val) {
                node->left = nodeStack.back();
                nodeStack.pop_back();
            }
            if (!nodeStack.empty()) {
                nodeStack.back()->right = node;
            }
            nodeStack.emplace_back(node);
        }
        return nodeStack.front();
    }
};
