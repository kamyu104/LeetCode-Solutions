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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> nodes;
        nodes.emplace_back(root->val);
        leftBoundary(root->left, &nodes);
        leaves(root->left, &nodes);
        leaves(root->right, &nodes);
        rightBoundary(root->right, &nodes);
        return nodes;
    }

private:
    void leftBoundary(TreeNode *root, vector<int> *nodes) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        nodes->emplace_back(root->val);
        if (!root->left) {
            leftBoundary(root->right, nodes);
        } else {
            leftBoundary(root->left, nodes);
        }
    }

    void rightBoundary(TreeNode *root, vector<int> *nodes) {
        if (!root || (!root->right && !root->left)) {
            return;
        }
        if (!root->right) {
            rightBoundary(root->left, nodes);
        } else {
            rightBoundary(root->right, nodes);
        }
        nodes->emplace_back(root->val);
    }
    
    void leaves(TreeNode *root, vector<int> *nodes) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            nodes->emplace_back(root->val);
            return;
        }
        leaves(root->left, nodes);
        leaves(root->right, nodes);
    }
};
