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
    TreeNode* balanceBST(TreeNode* root) {
        return orderedArrayToBst(inorderTraversal(root));
    }

private:
    TreeNode *orderedArrayToBst(const vector<int>& arr) {
        TreeNode *result = nullptr;
        vector<tuple<int, int, TreeNode**>> stk = {{0, arr.size(), &result}};
        while (!stk.empty()) {
            const auto [i, j, ret] = stk.back(); stk.pop_back();
            if (i >= j) {
                continue;
            }
            const auto& mid = i + (j - i) / 2;
            *ret = new TreeNode(arr[mid]);
            stk.emplace_back(mid + 1, j, &((*ret)->right));
            stk.emplace_back(i, mid, &((*ret)->left));
        }
        return result;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<pair<TreeNode *, bool>> stk;
        stk.emplace_back(root, false);
        while (!stk.empty()) {
            const auto [node, visited] = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            if (visited) {
                result.emplace_back(node->val);
            } else {
                stk.emplace_back(node->right, false);
                stk.emplace_back(node, true);
                stk.emplace_back(node->left, false);
            }
        }
        return result;
    }
};
