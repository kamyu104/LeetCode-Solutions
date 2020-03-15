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

// dfs solution with stack
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        return sortedArrayToBst(inorderTraversal(root));
    }

private:
    TreeNode *sortedArrayToBst(const vector<int>& arr) {
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

// Time:  O(n)
// Space: O(h)
// dfs solution with recursion
class Solution2 {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorderTraversalHelper(root, &arr);
        return sortedArrayToBstHelper(arr, 0, arr.size());
    }

private:
    TreeNode *sortedArrayToBstHelper(const vector<int>& arr, int i, int j) {
        if (i >= j) {
            return nullptr;
        }
        const auto& mid = i + (j - i) / 2;
        auto result = new TreeNode(arr[mid]);
        result->left = sortedArrayToBstHelper(arr, i, mid);
        result->right = sortedArrayToBstHelper(arr, mid + 1, j);
        return result;
    }
    
    void inorderTraversalHelper(TreeNode* root, vector<int> *arr) {
        if (!root) {
            return;
        }
        inorderTraversalHelper(root->left, arr);
        arr->emplace_back(root->val);
        inorderTraversalHelper(root->right, arr);
    }
};
