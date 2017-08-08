// Time:  O(n)
// Space: O(n * h)

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> lookup;
        vector<TreeNode*> result;
        postOrderTraversal(root, &lookup, &result);
        return result;
    }

private:
    string postOrderTraversal(TreeNode* node, unordered_map<string, int>* lookup, vector<TreeNode*> *result) {
        if (!node) {
            return "";
        }
        string s = "(";
        s += postOrderTraversal(node->left, lookup, result);
        s += to_string(node->val);
        s += postOrderTraversal(node->right, lookup, result);
        s += ")";
        if ((*lookup)[s] == 1) {
            result->emplace_back(node);
        }
        ++(*lookup)[s];
        return s;
    }
};
