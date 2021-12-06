// Time:  O(n)
// Space: O(h)

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto src = iter_dfs(root, startValue);
        auto dst = iter_dfs(root, destValue);
        while (!empty(src) && !empty(dst) && src.back() == dst.back()) {
            src.pop_back();
            dst.pop_back();
        }
        reverse(begin(dst), end(dst));
        return string(size(src), 'U') + dst;
    }

private:
    string iter_dfs(TreeNode *root, int val) {
        string path;
        vector<tuple<int, TreeNode *, char>> stk = {{1, root, ' '}};
        while (!empty(stk)) {
            auto [step, node, d] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (node->val == val) {
                    reverse(begin(path), end(path));
                    return path;
                }
                for (const auto& child : {node->left, node->right}) {
                    if (!child) {
                        continue;
                    }
                    stk.emplace_back(3, nullptr, ' ');
                    stk.emplace_back(1, child, ' ');
                    stk.emplace_back(2, nullptr, (child == node->left) ? 'L' : 'R');
                }
            } else if (step == 2) {
                path.push_back(d);
            } else if (step == 3) {
                path.pop_back();
            }
        }
        return "";
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string src, dst;
        dfs(root, startValue, &src);
        dfs(root, destValue, &dst);
        while (!empty(src) && !empty(dst) && src.back() == dst.back()) {
            src.pop_back();
            dst.pop_back();
        }
        reverse(begin(dst), end(dst));
        return string(size(src), 'U') + dst;
    }

private:
    bool dfs(TreeNode *curr, int val, string *path) {
        if (curr->val == val) {
            return true;
        }
        if (curr->left && dfs(curr->left, val, path)) {
            path->push_back('L');
        } else if (curr->right && dfs(curr->right, val, path)) {
            path->push_back('R');
        }
        return !empty(*path);
    }
};
