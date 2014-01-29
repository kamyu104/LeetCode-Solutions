// Time Complexity: O( (2n, n) / n ) ~= O( 4^n / n^(3/2) )
// Space Complexity: O( (2n, n) ) ~= O( 4^n / n^(1/2) )

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<TreeNode *> generateTrees(int n) {
            return generate(1, n);
        }
    private:
        vector<TreeNode *> generate(int begin, int end) {
            vector<TreeNode *> subTree;
            if(begin > end) {
                subTree.push_back(NULL);
            }

            for(int k = begin; k <= end; ++k) {
                vector<TreeNode *> leftSubTree = generate(begin, k - 1);
                vector<TreeNode *> rightSubTree = generate(k + 1, end);

                for(auto i : leftSubTree) {
                    for(auto j : rightSubTree) {
                        TreeNode *node = new TreeNode(k);
                        node->left = i;
                        node->right = j;
                        subTree.push_back(node);
                    }
                }
            }

            return subTree;
        }
};
