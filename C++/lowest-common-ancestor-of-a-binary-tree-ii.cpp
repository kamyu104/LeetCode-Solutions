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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return iter_dfs(root, p, q);
    }

private:
    TreeNode *iter_dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        TreeNode *result = nullptr;
        int ret = 0;
        vector<tuple<int, TreeNode *, unique_ptr<int>, unique_ptr<int>, int*>> stk;
        stk.emplace_back(1, node, nullptr,  nullptr, &ret);
        while (!empty(stk)) {
            const auto [step, node, ret1, ret2, ret] = move(stk.back()); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                auto ret1 = make_unique<int>(), ret2 = make_unique<int>();
                auto p1 = ret1.get(), p2 = ret2.get();
                stk.emplace_back(2, node, move(ret1), move(ret2), ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, p2);
                stk.emplace_back(1, node->left, nullptr, nullptr, p1);
            } else if (step == 2) {
                auto curr = int(node == p || node == q);
                if (curr + *ret1 + *ret2 == 2 && !result) {
                    result = node;
                }
                *ret = curr + *ret1 + *ret2;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result = nullptr;
        dfs(root, p, q, &result);
        return result;
    }

private:
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode** result) {
        if (!node) {
            return 0;
        }
        auto left = dfs(node->left, p, q, result);
        auto right = dfs(node->right, p, q, result);
        auto curr = int(node == p || node == q);
        if (curr + left + right == 2 && !(*result)) {
            *result = node;
        }
        return curr + left + right;
    }
};
