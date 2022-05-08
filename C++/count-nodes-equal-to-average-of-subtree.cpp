// Time:  O(n)
// Space: O(h)

// dfs
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        const auto& iter_dfs = [&](TreeNode *root) {
            int result = 0;
            using RET = pair<int, int>;
            RET ret;
            vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk;
            stk.emplace_back(1, root, nullptr, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, node, ret1, ret2, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!node) {
                        continue;
                    }
                    auto ret1 = make_shared<RET>(), ret2 = make_shared<RET>();
                    stk.emplace_back(2, node, ret1, ret2, ret);
                    stk.emplace_back(1, node->right, nullptr, nullptr, ret2.get());
                    stk.emplace_back(1, node->left, nullptr, nullptr, ret1.get());
                } else if (step == 2) {
                    (*ret).first = (*ret1).first + (*ret2).first + node->val;
                    (*ret).second = (*ret1).second + (*ret2).second + 1;
                    result += static_cast<int>((*ret).first / (*ret).second == node->val);
                }
            }
            return result;
        };

        return iter_dfs(root);
    }
};

// Time:  O(n)
// Space: O(h)
// dfs
class Solution2 {
public:
    int averageOfSubtree(TreeNode* root) {
        function<tuple<int, int, int>(TreeNode*)> dfs = [&](TreeNode *node) {
            if (!node) {
                return make_tuple(0, 0, 0);
            }
            const auto& left = dfs(node->left);
            const auto& right = dfs(node->right);
            return make_tuple(get<0>(left) + get<0>(right) + node->val,
                              get<1>(left) + get<1>(right) + 1,
                              get<2>(left) + get<2>(right) + 
                              static_cast<int>((get<0>(left) + get<0>(right) + node->val) /
                                               (get<1>(left) + get<1>(right) + 1) == node->val));
        };

        return get<2>(dfs(root));
    }
};
