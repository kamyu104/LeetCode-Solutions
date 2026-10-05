// Time: O(n)
// Space: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int balanceHelper(TreeNode* node, bool& balanced){
        int leftBal = 0;
        int rightBal = 0;

        if(node->left != nullptr){
            leftBal = balanceHelper(node->left, balanced);
        }
        if(node->right != nullptr){
            rightBal = balanceHelper(node->right, balanced);
        }

        if(leftBal - rightBal > 1 || leftBal - rightBal < -1){
            balanced = false;
        }

        if(leftBal > rightBal){
            return 1 + leftBal;
        }
        else{
            return 1 + rightBal;
        }
    }


    bool isBalanced(TreeNode* root) {
        if(root != nullptr){
            bool balanced = true;
            balanceHelper(root, balanced);

            if(!balanced){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
};