// Time:  O(n)
// Space: O(w)

class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> q = {{root, nullptr}};
        while (!empty(q)) {
            unordered_map<TreeNode*, TreeNode*> new_q;
            for (const auto& [node, parent] : q) {
                if (q.count(node->right)) {
                    if (parent->left == node) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                    return root;
                }
                if (node->left) {
                    new_q[node->left] = node;
                }
                if (node->right) {
                    new_q[node->right] = node;
                }
            }
            q = move(new_q);
        }
        return nullptr;
    }
};
