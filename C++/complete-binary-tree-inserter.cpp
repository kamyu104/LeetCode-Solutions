// Time:  ctor:     O(n)
//        insert:   O(1)
//        get_root: O(1)
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        tree_.emplace_back(root);
        for (int i = 0; i < tree_.size(); ++i) {
            if (tree_[i]->left) {
                tree_.emplace_back(tree_[i]->left);
            }
            if (tree_[i]->right) {
                tree_.emplace_back(tree_[i]->right);
            }
        }
    }

    int insert(int v) {
        auto n = tree_.size();
        auto node = new TreeNode(v);
        tree_.emplace_back(node);
        if (n % 2) {
            tree_[(n - 1) / 2]->left = node;
        } else {
            tree_[(n - 1) / 2]->right = node;
        }
        return tree_[(n - 1) / 2]->val;
    }

    TreeNode* get_root() {
        return tree_[0];
    }
    
private:
    vector<TreeNode*> tree_;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
 
