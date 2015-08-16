// Time:  O(n * h)
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<TreeNode *> path;
        binaryTreePathsRecu(root, &path, &result);
        return result;
    }

    void binaryTreePathsRecu(TreeNode *node, vector<TreeNode *> *path, vector<string> *result) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            string ans = "";
            for (const auto& n : *path) {
                ans.append(to_string(n->val).append("->"));
            }
            result->emplace_back(move(ans.append(to_string(node->val))));
        }
            
        if (node->left != nullptr) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->left, path, result);
            path->pop_back();
        }

        if (node->right != nullptr) {
            path->emplace_back(node);
            binaryTreePathsRecu(node->right, path, result);
            path->pop_back();
        }
    }
};
