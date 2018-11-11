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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int result = 0;
        vector<TreeNode*> s{root};
        while (!s.empty()) {
            auto node = s.back(); s.pop_back();
            if (node) {
                if (L <= node->val && node->val <= R) {
                    result += node->val;
                }
                if (L <= node->val) {
                    s.emplace_back(node->left);
                }
                if (node->val <= R) {
                    s.emplace_back(node->right);
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        return (root == nullptr) ? 
            0 : (L <= root->val && root->val <= R) * root->val +
                ((L <= root->val) ? rangeSumBST(root->left, L, R) : 0) +
                ((root->val <= R) ? rangeSumBST(root->right, L, R) : 0);
    }   
};

