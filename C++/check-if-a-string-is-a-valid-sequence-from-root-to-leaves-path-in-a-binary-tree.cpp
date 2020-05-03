// Time:  O(n)
// Space: O(w)

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
// bfs solution
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        vector<TreeNode *> q = {root};
        for (int depth = 0; depth < arr.size(); ++depth) {
            vector<TreeNode *> new_q;
            while (!q.empty()) {
                const auto node = q.back(); q.pop_back();
                if (!node || node->val != arr[depth]) {
                    continue;
                }
                if (depth + 1 == arr.size() && node->left == node->right) {
                    return true;
                }
                new_q.emplace_back(node->left);
                new_q.emplace_back(node->right);            
            }
            q = move(new_q);
        }
        return false;
    }
};

// Time:  O(n)
// Space: O(h)
// dfs solution with stack
class Solution2 {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        vector<pair<TreeNode *, int>> s = {{root, 0}};
        while (!s.empty()) {
            const auto [node, depth] = s.back(); s.pop_back();
            if (!node || depth == arr.size() || node->val != arr[depth]) {
                continue;
            }
            if (depth + 1 == arr.size() && node->left == node->right) {
                return true;
            }
            s.emplace_back(node->right, depth + 1);   
            s.emplace_back(node->left, depth + 1);
        }
        return false;
    }
};

// Time:  O(n)
// Space: O(h)
// dfs solution with recursion
class Solution3 {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }

private:
    bool dfs(TreeNode *node, const vector<int>& arr, int depth) {
        if (!node || depth == arr.size() || node->val != arr[depth]) {
            return false;
        }
        if (depth + 1 == arr.size() && node->left == node->right) {
            return true;
        }
        return dfs(node->left, arr, depth + 1) || dfs(node->right, arr, depth + 1);
    }
};
