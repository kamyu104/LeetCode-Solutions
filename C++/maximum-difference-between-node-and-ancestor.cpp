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

// iterative stack solution
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        using NODE = tuple<TreeNode*, int, int>;
        int result = 0;
        vector<NODE> stack{{root, 0, numeric_limits<int>::max()}};
        while (!stack.empty()) {
            TreeNode *node; int mx, mn;
            tie(node, mx, mn) = stack.back(); stack.pop_back();
            if (!node) {
                continue;
            }
            result = max(result, max(mx - node->val, node->val - mn));
            mx = max(mx, node->val);
            mn = min(mn, node->val);
            stack.emplace_back(node->left, mx, mn);
            stack.emplace_back(node->right, mx, mn);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
// recursive solution
class Solution2 {
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiffHelper(root, 0, numeric_limits<int>::max());
    }

private:
    int maxAncestorDiffHelper(TreeNode* node, int mx, int mn) {
        if (!node) {
            return 0;
        }
        int result = max(mx - node->val, node->val - mn);
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        result = max(result, maxAncestorDiffHelper(node->left, mx, mn));
        result = max(result, maxAncestorDiffHelper(node->right, mx, mn));
        return result;
    }
};
