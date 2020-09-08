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
    int diameterOfBinaryTree(TreeNode* root) {
        return iter_dfs(root);
    }

private:
    int iter_dfs(TreeNode *node) {
        int result = 0;
 
        vector<function<void()>> stk;
        function<void(TreeNode*, int*)> divide;
        function<void(TreeNode*, shared_ptr<int>&, shared_ptr<int>&, int *)> conquer;
        divide = [&](TreeNode *node, int *ret) {
            if (!node) {
                return;
            }
            auto ret1 = make_shared<int>(), ret2 = make_shared<int>();
            stk.emplace_back(bind(conquer, node, ret1, ret2, ret));
            stk.emplace_back(bind(divide, node->right, ret2.get()));
            stk.emplace_back(bind(divide, node->left, ret1.get()));
        };
        conquer = [&](TreeNode *node, shared_ptr<int> ret1, shared_ptr<int> ret2, int *ret) {
            result = max(result, *ret1 + *ret2);
            *ret = 1 + max(*ret1, *ret2);
        };

        int max_h = 0;
        stk.emplace_back(bind(divide, node, &max_h));
        while (!stk.empty()) {
            auto cb = move(stk.back()); stk.pop_back();
            cb();
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return iter_dfs(root);
    }

private:
    int iter_dfs(TreeNode *node) {
        int result = 0, max_h = 0;
        vector<tuple<int, TreeNode *, unique_ptr<int>, unique_ptr<int>, int*>> stk;
        stk.emplace_back(1, node, nullptr,  nullptr, &max_h);
        while (!stk.empty()) {
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
                result = max(result, *ret1 + *ret2);
                *ret = 1 + max(*ret1, *ret2);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution3 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }

private:
    pair<int, int> dfs(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }
        const auto& [left_d, left_h] = dfs(root->left);
        const auto& [right_d, right_h] = dfs(root->right);
        return {max({left_d, right_d, left_h + right_h}), 1 + max(left_h, right_h)};
    }
};
