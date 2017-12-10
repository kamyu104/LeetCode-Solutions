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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<int, vector<int>> neighbors;
        unordered_set<int> leaves;
        traverse(root, &neighbors, &leaves);
        vector<int> q{k};
        unordered_set<int> lookup{k};
        while (!q.empty()) {
            vector<int> next_q;
            for (const auto& u : q) {
                if (leaves.count(u)) {
                    return u;
                }
                for (const auto& v : neighbors[u]) {
                    if (lookup.count(v)) {
                        continue;
                    }
                    lookup.emplace(v);
                    next_q.emplace_back(v);
                }
            }
            swap(q, next_q);
        }
        return 0;
    }
    
private:
    void traverse(TreeNode *node,
                  unordered_map<int, vector<int>> *neighbors,
                  unordered_set<int> *leaves) {

        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            leaves->emplace(node->val);
            return;
        }
        if (node->left) {
            (*neighbors)[node->val].emplace_back(node->left->val);
            (*neighbors)[node->left->val].emplace_back(node->val);
            traverse(node->left, neighbors, leaves);
        }
        if (node->right) {
            (*neighbors)[node->val].emplace_back(node->right->val);
            (*neighbors)[node->right->val].emplace_back(node->val);
            traverse(node->right, neighbors, leaves);
        }
    }
};
