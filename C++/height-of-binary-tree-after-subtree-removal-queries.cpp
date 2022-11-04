// Time:  O(n)
// Space: O(n)

// iterative dfs
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, pair<int, int>> top;
        unordered_map<int, int> depth, height;
        const auto& iter_dfs = [&]() {
            vector<tuple<int, TreeNode *, int>> stk = {{1, root, 0}};
            while (!empty(stk)) {
                const auto [step, curr, d] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!curr) {
                        continue;
                    }
                    stk.emplace_back(2, curr, d);
                    stk.emplace_back(1, curr->right, d + 1);
                    stk.emplace_back(1, curr->left, d + 1);
                } else if (step == 2) {
                    const int h = 1 + max(curr->left ? height[curr->left->val] : 0,
                                          curr->right ? height[curr->right->val] : 0);
                    if (h > top[d].first) {
                        top[d].second = top[d].first;
                        top[d].first = h;
                    } else if (h > top[d].second) {
                        top[d].second = h;
                    }
                    depth[curr->val] = d;
                    height[curr->val] = h;
                }
            }
        };

        iter_dfs();
        vector<int> result;
        for (const auto& q: queries) {
            result.emplace_back((depth[q] - 1) + (height[q] != top[depth[q]].first ? top[depth[q]].first : top[depth[q]].second));
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs
class Solution2 {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, pair<int, int>> top;
        unordered_map<int, int> depth, height;
        const function<int(TreeNode *curr, int d)> dfs = [&](const auto& curr, const auto& d) {
            if (!curr) {
                return 0;
            }
            const int h = 1 + max(dfs(curr->left, d + 1), dfs(curr->right, d + 1));
            if (h > top[d].first) {
                top[d].second = top[d].first;
                top[d].first = h;
            } else if (h > top[d].second) {
                top[d].second = h;
            }
            depth[curr->val] = d;
            height[curr->val] = h;
            return h;
        };

        dfs(root, 0);
        vector<int> result;
        for (const auto& q: queries) {
            result.emplace_back((depth[q] - 1) + (height[q] != top[depth[q]].first ? top[depth[q]].first : top[depth[q]].second));
        }
        return result;
    }
};
