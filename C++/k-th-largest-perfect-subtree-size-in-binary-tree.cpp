// Time:  O(n)
// Space: O(n)

// iterative dfs, quick select
class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        const auto& iter_dfs = [&]() {
            vector<int> result;
            using RET = int;
            RET ret = 0;
            vector<tuple<int, TreeNode *, shared_ptr<vector<int>>, RET *>> stk = {{1, root, nullptr, &ret}};
            while (!empty(stk)) {
                auto [step, curr, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!curr) {
                        *ret = 0;
                        result.emplace_back(*ret);
                        continue;
                    }
                    auto new_ret = make_shared<vector<int>>(2);
                    stk.emplace_back(2, nullptr, new_ret, ret);
                    stk.emplace_back(1, curr->right, nullptr, &((*new_ret)[1]));
                    stk.emplace_back(1, curr->left, nullptr, &((*new_ret)[0]));
                } else if (step == 2) {
                    *ret = (*new_ret)[0] == (*new_ret)[1] && (*new_ret)[1] != -1 ? (*new_ret)[0] + (*new_ret)[1] + 1 : -1;
                    result.emplace_back(*ret);
                }
            }
            return result;
        };
    
        auto result = iter_dfs();
        if (k - 1 >= size(result)) {
            return -1;
        }
        nth_element(begin(result), begin(result) + (k - 1), end(result), greater<int>());
        return result[k - 1] ? result[k - 1] : -1;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, quick select
class Solution2 {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> result;
        const function<void (TreeNode *)> dfs = [&](auto curr) {
            if (!curr) {
                result.emplace_back(0);
                return;
            }
            dfs(curr->left);
            const int left = result.back();
            dfs(curr->right);
            const int right = result.back();
            result.emplace_back(left == right && right != -1 ? left + right + 1 : -1);
        };
    
        dfs(root);
        if (k - 1 >= size(result)) {
            return -1;
        }
        nth_element(begin(result), begin(result) + (k - 1), end(result), greater<int>());
        return result[k - 1] ? result[k - 1] : -1;
    }
};
