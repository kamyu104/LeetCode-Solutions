// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// bfs solution
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode *> q1({root1}), q2({root2});
        while (!q1.empty() && !q2.empty()) {
            auto node1 = q1.front(); q1.pop();
            auto node2 = q2.front(); q2.pop();
            if (!node1 && !node2) {
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            if ((!node1->left && !node2->right) ||
                (node1->left && node2->right && node1->left->val == node2->right->val)) {
                q1.emplace(node1->right);
                q1.emplace(node1->left);
            } else {
                q1.emplace(node1->left);
                q1.emplace(node1->right);
            }
            q2.emplace(node2->left);
            q2.emplace(node2->right);
        }
        return q1.empty() && q2.empty();
    }
};

// Time:  O(n)
// Space: O(h)
// iterative dfs solution
class Solution2 {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode *> stk1 = {root1}, stk2 = {root2};
        while (!stk1.empty() && !stk2.empty()) {
            auto node1 = stk1.back(); stk1.pop_back();
            auto node2 = stk2.back(); stk2.pop_back();
            if (!node1 && !node2) {
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            if ((!node1->left && !node2->right) ||
                (node1->left && node2->right && node1->left->val == node2->right->val)) {
                stk1.emplace_back(node1->right);
                stk1.emplace_back(node1->left);
            } else {
                stk1.emplace_back(node1->left);
                stk1.emplace_back(node1->right);
            }
            stk2.emplace_back(node2->left);
            stk2.emplace_back(node2->right);
        }
        return stk1.empty() && stk2.empty();
    }
};

// Time:  O(n)
// Space: O(h)
// recursive dfs solution
class Solution3 {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }

        return (flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right) ||
                flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left));
    }
};
