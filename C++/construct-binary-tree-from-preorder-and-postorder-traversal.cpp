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
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> s;
        s.emplace_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            auto node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]) {
                s.pop_back(), ++j;
            }
            if (s.back()->left == nullptr) {
                s.back()->left = node;
            } else {
                s.back()->right = node;
            }
            s.emplace_back(node);
        }
        return s[0];
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, size_t> post_entry_idx_map;
        for (size_t i = 0; i < post.size(); ++i) {
            post_entry_idx_map[post[i]] = i;
        }
        return constructFromPrePostHelper(pre, 0, pre.size(), post, 0, post.size(),
                                          post_entry_idx_map);
    }

private:
    TreeNode *constructFromPrePostHelper(const vector<int>& pre, size_t pre_s, size_t pre_e,
                                         const vector<int>& post, size_t post_s, size_t post_e,
                                         const unordered_map<int, size_t>& post_entry_idx_map) {
        if (pre_s >= pre_e || post_s >= post_e) {
            return nullptr;
        }
        auto node = new TreeNode(pre[pre_s]);
        if (pre_e - pre_s > 1) {
            auto left_tree_size = post_entry_idx_map.at(pre[pre_s + 1]) - post_s + 1;         
            node->left = constructFromPrePostHelper(pre, pre_s + 1, pre_s + 1 + left_tree_size, 
                                                    post, post_s, post_s + left_tree_size,
                                                    post_entry_idx_map);
            node->right = constructFromPrePostHelper(pre, pre_s + 1 + left_tree_size, pre_e,
                                                     post, post_s + left_tree_size, post_e - 1,
                                                     post_entry_idx_map);
        }
        return node;
    }
};
