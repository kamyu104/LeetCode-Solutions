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

// Time:  O(n)
// Space: O(h)
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        return iter_dfs(distance, root);
    }

private:
    int iter_dfs(int distance, TreeNode *root) {
        using RET = unordered_map<int, int>;
        int result = 0;
        RET ret;
        vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk = {{1, root, nullptr, nullptr, &ret}};
        while (!stk.empty()) {
            const auto [step, node, left, right, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                if (!node->left && !node->right) {
                    (*ret)[0] = 1;
                    continue;
                }
                const auto& left = make_shared<RET>(), &right = make_shared<RET>();
                stk.emplace_back(2, nullptr, left, right, ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, right.get());
                stk.emplace_back(1, node->left, nullptr, nullptr, left.get());
            } else {
                for (const auto& [left_d, left_c] : *left) {
                    for (const auto& [right_d, right_c] : *right) {
                        if (left_d + right_d + 2 <= distance) {
                            result += left_c * right_c;
                        }
                    }
                }
                for (const auto& [left_d, left_c] : *left) {
                    (*ret)[left_d + 1] += left_c;
                }
                for (const auto& [right_d, right_c] : *right) {
                    (*ret)[right_d + 1] += right_c;
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
    int countPairs(TreeNode* root, int distance) {
        return dfs(distance, root).first;
    }

private:
    pair<int, unordered_map<int, int>> dfs(int distance, TreeNode *node) {
        if (!node) {
            return {0, {}};
        }
        if (!node->left && !node->right) {
            return {0, {{0, 1}}};
        }
        const auto& left = dfs(distance, node->left);
        const auto& right = dfs(distance, node->right);
        int result = left.first + right.first;
        for (const auto& [left_d, left_c] : left.second) {
            for (const auto& [right_d, right_c] : right.second) {
                if (left_d + right_d + 2 <= distance) {
                    result += left_c * right_c;
                }
            }
        }
        unordered_map<int, int> count;
        for (const auto& [left_d, left_c] : left.second) {
            count[left_d + 1] += left_c;
        }
        for (const auto& [right_d, right_c] : right.second) {
            count[right_d + 1] += right_c;
        }
        return {result, count};
    }
};
