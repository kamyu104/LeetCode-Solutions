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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> counts;
        int max_count = 0;
        countSubtreeSumsHelper(root, &counts, &max_count);
        
        vector<int> result;
        for (const auto& kvp : counts){
            if (kvp.second == max_count) {
                result.emplace_back(kvp.first);
            }
        }
        return result;
    }

private:
    int countSubtreeSumsHelper(TreeNode *root, unordered_map<int,int> *counts, int *max_count) {
        if (!root) {
            return 0;
        }
        auto sum = root->val +
                   countSubtreeSumsHelper(root->left, counts, max_count) +
                   countSubtreeSumsHelper(root->right, counts, max_count);
        ++(*counts)[sum];
        (*max_count) = max((*max_count), (*counts)[sum]);
        return sum;
    }
};
