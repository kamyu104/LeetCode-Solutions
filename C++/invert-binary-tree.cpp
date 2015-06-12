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

// Time:  O(n)
// Space: O(w), w is the max number of nodes of the levels.
// BFS solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            queue<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};
 
// Time:  O(n)
// Space: O(h)
// Stack solution.
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            stack<TreeNode*> nodes;
            nodes.emplace(root);
            while (!nodes.empty()) {
                auto node = nodes.top();
                nodes.pop();
                swap(node->left, node->right);
                if (node->left != nullptr) {
                    nodes.emplace(node->left);
                }
                if (node->right != nullptr) {
                    nodes.emplace(node->right);
                }
            }
        }
        return root;
    }
};

// Time:  O(n)
// Space: O(h) 
// DFS, Recursive solution.
class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
          TreeNode *left = root->left;
          TreeNode *right = root->right;
          root->left = invertTree(right);
          root->right = invertTree(left);
        }
        return root;
    }
};
