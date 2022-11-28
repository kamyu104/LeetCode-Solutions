// Time:  O(n + qlogn)
// Space: O(n)

// iterative dfs, binary search
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        const auto& iter_dfs = [&]() {
            vector<int> inorder;
            vector<pair<int, TreeNode *>> stk = {{1, root}};
            while (!empty(stk)) {
                const auto [step, node] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!node) {
                        continue;
                    }
                    stk.emplace_back(1, node->right);
                    stk.emplace_back(2, node);
                    stk.emplace_back(1, node->left);
                } else if (step == 2) {
                    inorder.emplace_back(node->val);
                }
            }
            return inorder;
        };

        const auto& inorder = iter_dfs();
        vector<vector<int>> result;
        for (const auto& q : queries) {
            const auto cit = lower_bound(cbegin(inorder), cend(inorder), q);
            if (cit == cend(inorder)) {
                result.push_back({*prev(cit), -1});
            } else if (*cit == q) {
                result.push_back({*cit, *cit});
            } else if (cit == cbegin(inorder)) {
                result.push_back({-1, *cit});
            } else {
                result.push_back({*prev(cit), *cit});
            }
        }
        return result;
    }
};

// Time:  O(n + qlogn)
// Space: O(n)
// dfs, binary search
class Solution2 {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder;
        const function<void (TreeNode*)> dfs = [&](TreeNode *node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            inorder.emplace_back(node->val);
            dfs(node->right);
        };

        dfs(root);
        vector<vector<int>> result;
        for (const auto& q : queries) {
            const auto cit = lower_bound(cbegin(inorder), cend(inorder), q);
            if (cit == cend(inorder)) {
                result.push_back({*prev(cit), -1});
            } else if (*cit == q) {
                result.push_back({*cit, *cit});
            } else if (cit == cbegin(inorder)) {
                result.push_back({-1, *cit});
            } else {
                result.push_back({*prev(cit), *cit});
            }
        }
        return result;
    }
};
