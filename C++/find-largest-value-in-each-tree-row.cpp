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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        largestValuesHelper(root, 0, &result);
        return result;
    }
private:
    void largestValuesHelper(TreeNode* root, int depth, vector<int> *result) {
        if (!root) {
            return;
        }
        if (depth == result->size()) {
            result->emplace_back(root->val);
        } else {
            (*result)[depth] = max((*result)[depth], root->val);
        }
        largestValuesHelper(root->left, depth + 1, result);
        largestValuesHelper(root->right, depth + 1, result);
    }
 };
 
// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        vector<TreeNode*> curr, next;
        curr.emplace_back(root);
        while (!curr.empty()) {
            int max_val = numeric_limits<int>::min();
            next.clear();
            for (const auto& node : curr) {
                max_val = max(max_val, node->val);
                if (node->left) {
                    next.emplace_back(node->left);
                }
                if (node->right) {
                    next.emplace_back(node->right);
                }
            }
            result.emplace_back(max_val);
            swap(curr, next);
        }
        return result;
    }
};
