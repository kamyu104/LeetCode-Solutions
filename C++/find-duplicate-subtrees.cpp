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
        unordered_map<string, vector<TreeNode*>> lookup;
        vector<TreeNode*> result;
        serialize(root, &lookup);
        for (auto it = lookup.begin(); it != lookup.end(); ++it) {
            if (it->second.size() > 1) {
                result.emplace_back(it->second[0]);
            }
        }
        return result;
    }

private:
    string serializeHelper(TreeNode* node, unordered_map<string, vector<TreeNode*>>* lookup) {
        if (!node) {
            return "";
        }
        string s = "(";
        s += serializeHelper(node->left, lookup);
        s += to_string(node->val);
        s += serializeHelper(node->right, lookup);
        s += ")";
        (*lookup)[s].emplace_back(node);
        return s;
    }
};
