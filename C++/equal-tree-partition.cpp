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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> lookup;
        auto total = getSumHelper(root, &lookup);
        if (total == 0) {
            return lookup[total] > 1;
        }
        return total % 2 == 0 && lookup.count(total / 2);
    }

private:
    int getSumHelper(TreeNode* root,  unordered_map<int, int> *lookup) {
        if (!root) {
            return 0;
        }
        int total = root->val + 
                    getSumHelper(root->left, lookup) +
                    getSumHelper(root->right, lookup);
        ++(*lookup)[total];
        return total;
    }
};
