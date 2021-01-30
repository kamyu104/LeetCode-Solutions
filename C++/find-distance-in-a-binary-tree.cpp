// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        return iter_dfs(root, p, q);
    }

private:
    int iter_dfs(TreeNode *node, int p, int q) {
        int result = 0, dist = -1;
        vector<tuple<int, TreeNode *, unique_ptr<int>, unique_ptr<int>, int*>> stk;
        stk.emplace_back(1, node, nullptr,  nullptr, &dist);
        while (!empty(stk)) {
            const auto [step, node, ret1, ret2, ret] = move(stk.back()); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                auto ret1 = make_unique<int>(-1), ret2 = make_unique<int>(-1);
                auto p1 = ret1.get(), p2 = ret2.get();
                stk.emplace_back(2, node, move(ret1), move(ret2), ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, p2);
                stk.emplace_back(1, node->left, nullptr, nullptr, p1);
            } else if (step == 2) {
                if (node->val == p || node->val == q) {
                    if (*ret1 == -1 && *ret2 == -1) {
                        *ret = 0;
                    }
                    result = (*ret1 != -1) ? *ret1 + 1 : *ret2 + 1;
                } else if (*ret1 != -1 && *ret2 != -1) {
                    result = *ret1 + *ret2 + 2;
                } else if (*ret1 != -1) {
                    *ret = *ret1 + 1;
                } else if (*ret2 != -1) {
                    *ret = *ret2 + 1;
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int findDistance(TreeNode* root, int p, int q) {
        int result = 0;
        dfs(root, p, q, &result);
        return result;
    }

private:
    int dfs(TreeNode *node, int p, int q, int *result) {
        if (!node) {
            return -1;
        }
        auto left = dfs(node->left, p, q, result);
        auto right = dfs(node->right, p, q, result);
        if (node->val == p || node->val == q) {
            if (left == -1 && right == -1) {
                return 0;
            }
            *result = (left != -1) ? left + 1 : right + 1;
        } else if (left != -1 && right != -1) {
            *result = left + right + 2;
        } else if (left != -1) {
            return left + 1;
        } else if (right != -1) {
            return right + 1;
        }
        return -1;
    }
};
