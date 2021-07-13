// Time:  O(n)
// Space: O(n)

class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaf_vals_set;
        unordered_map<int, TreeNode*> val_to_root;
        find_leaves_and_roots(trees, &leaf_vals_set, &val_to_root);    
        const auto& root = find_root(trees, leaf_vals_set, val_to_root);
        return merge_bsts(root, leaf_vals_set, &val_to_root);
    }

private:
    void find_leaves_and_roots(
        const vector<TreeNode*>& trees,
        unordered_set<int> *leaf_vals_set,
        unordered_map<int, TreeNode*> *val_to_root) {

        for (const auto& root : trees) {
            (*val_to_root)[root->val] = root;
            vector<TreeNode*> q = {root};
            while (!empty(q)) {
                vector<TreeNode*> new_q;
                for (const auto& node : q) {
                    if (!node->left && !node->right) {
                        if (node != root) {
                            leaf_vals_set->emplace(node->val);
                        }
                        continue;
                    }
                    if (node->left) {
                        new_q.emplace_back(node->left);
                    }
                    if (node->right) {
                        new_q.emplace_back(node->right);
                    }
                }
                q = move(new_q);
            }
        }
    }

    TreeNode* find_root(
        const vector<TreeNode*>& trees,
        const unordered_set<int>& leaf_vals_set,
        const unordered_map<int, TreeNode*>& val_to_root) {

        TreeNode *root = nullptr;
        for (const auto& node : trees) {
            if (leaf_vals_set.count(node->val)) {
                continue;
            }
            if (root) {  // multiple roots
                return nullptr;
            }
            root = node;
        }
        return root;
    }

    TreeNode* merge_bsts(
        TreeNode *root,
        const unordered_set<int>& leaf_vals_set,
        unordered_map<int, TreeNode*> *val_to_root) {

        if (!root) {
            return nullptr;
        }
        val_to_root->erase(root->val);
        vector<tuple<TreeNode*, int, int>> q = {{root, numeric_limits<int>::min(), numeric_limits<int>::max()}};
        while (!empty(q)) {
            vector<tuple<TreeNode*, int, int>> new_q;
            for (const auto& [node, left, right] : q) {
                if (!(left < node->val && node->val < right)) {
                    return nullptr;
                }
                if (node->left) {
                    if (leaf_vals_set.count(node->left->val) && val_to_root->count(node->left->val)) {
                        node->left = (*val_to_root)[node->left->val];
                        val_to_root->erase(node->left->val);
                    }
                    new_q.emplace_back(node->left, left, node->val);
                }
                if (node->right) {
                    if (leaf_vals_set.count(node->right->val) && val_to_root->count(node->right->val)) {
                        node->right = (*val_to_root)[node->right->val];
                        val_to_root->erase(node->right->val);
                    }
                    new_q.emplace_back(node->right, node->val, right);
                }
            }
            q = move(new_q);
        }
        return empty(*val_to_root) ? root : nullptr;
    }
};
