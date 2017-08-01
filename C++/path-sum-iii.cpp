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
    int pathSum(TreeNode* root, int sum) {        
        unordered_map<int, int> lookup;
        lookup[0] = 1;
        return pathSumHelper(root, 0, sum, &lookup);
    }

private:
    int pathSumHelper(TreeNode* root, int curr, int sum, unordered_map<int, int> *lookup) {
        if (!root) {
            return 0;
        }
        curr += root->val;
        int result = lookup->count(curr - sum) ? (*lookup)[curr - sum] : 0;
        ++(*lookup)[curr];
        result += pathSumHelper(root->left, curr, sum, lookup) + pathSumHelper(root->right, curr, sum, lookup);
        --(*lookup)[curr];
        if ((*lookup)[curr] == 0) {
            lookup->erase(curr);
        }
        return result;
    }
};


// Time:  O(n^2)
// Space: O(h)
class Solution2 {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return pathSumHelper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSumHelper(TreeNode* root, int prev, int sum) {
        if (!root) {
            return 0;
        }
        int curr = prev + root->val;
        return (curr == sum) + pathSumHelper(root->left, curr, sum) + pathSumHelper(root->right, curr, sum);
    }
};
