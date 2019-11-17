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
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root, 0, &lookup_);
    }
    
    bool find(int target) {
        return lookup_.count(target);
    }

private:
    void dfs(TreeNode *node, int v, unordered_set<int> *lookup) {
        if (!node) {
            return;
        }
        node->val = v;
        lookup->emplace(v);
        dfs(node->left, 2 * v + 1, lookup);
        dfs(node->right, 2 * v + 2, lookup);
    }

    unordered_set<int> lookup_;
};
