// Time:  O(n)
// Space: O(h)

// dfs with stack
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        static unordered_map<int, function<int(int, int)>> OP = {
            {2, [](int x, int y) { return x | y; }},
            {3, [](int x, int y) { return x & y; }},
        };

        const auto& iter_dfs = [&]() {
            using RET = int;
            RET ret;
            vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk;
            stk.emplace_back(1, root, nullptr, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, node, ret1, ret2, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (node->left == node->right) {
                        (*ret) = node->val;
                        continue;
                    }
                    auto ret1 = make_shared<RET>(), ret2 = make_shared<RET>();
                    stk.emplace_back(2, node, ret1, ret2, ret);
                    stk.emplace_back(1, node->right, nullptr, nullptr, ret2.get());
                    stk.emplace_back(1, node->left, nullptr, nullptr, ret1.get());
                } else if (step == 2) {
                    *ret = OP[node->val](*ret1, *ret2);
                }
            }
            return ret;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(h)
// dfs with recursion
class Solution2 {
public:
    bool evaluateTree(TreeNode* root) {
        static unordered_map<int, function<int(int, int)>> OP = {
            {2, [](int x, int y) { return x | y; }},
            {3, [](int x, int y) { return x & y; }},
        };

        function<int (TreeNode*)> dfs = [&](TreeNode *node) {
            if (node->left == node->right) {
                return node->val;
            }
            return OP[node->val](dfs(node->left), dfs(node->right));
        };

        return dfs(root);
    }
};
