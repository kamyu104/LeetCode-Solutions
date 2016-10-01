// Time:  O(n)
// Space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, size_t> in_entry_idx_map;
        for (size_t i = 0; i < inorder.size(); ++i) {
            in_entry_idx_map.emplace(inorder[i], i);
        }
        return ReconstructPostInOrdersHelper(postorder, 0, postorder.size(), inorder, 0, inorder.size(),
                                             in_entry_idx_map);
    }

    TreeNode * ReconstructPostInOrdersHelper(const vector<int>& postorder, size_t post_s, size_t post_e,
                                             const vector<int>& inorder, size_t in_s, size_t in_e,
                                             const unordered_map<int, size_t>& in_entry_idx_map) {
        if (post_s == post_e || in_s == in_e) {
            return nullptr;
        }
        
        auto idx = in_entry_idx_map.at(postorder[post_e - 1]);
        auto left_tree_size = idx - in_s;

        TreeNode *node = new TreeNode(postorder[post_e - 1]);
        // Recursively builds the left subtree.
        node->left =ReconstructPostInOrdersHelper(postorder, post_s, post_s + left_tree_size,
                                                  inorder, in_s, idx, in_entry_idx_map);
        // Recursively builds the right subtree.
        node->right = ReconstructPostInOrdersHelper(postorder, post_s + left_tree_size, post_e - 1,
                                                    inorder, idx + 1, in_e, in_entry_idx_map);
        return node;
    }
};
