// Time Complexity: O(n)
// Space Complexity: O(1)

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
        void recoverTree(TreeNode *root) {
            MorrisTraversal(root);
        }

    private:
        /* Function to traverse binary tree without recursion and 
           without stack */
        void MorrisTraversal(TreeNode *root)
        {
            if(root == NULL)
                return; 

            pair<TreeNode *, TreeNode *> broken;
            TreeNode *cur = root;
            TreeNode *pre = NULL;

            while(cur != NULL)
            {                 
                if(cur->left == NULL)
                {
                    detect(broken, pre, cur);
                    pre = cur;
                    cur = cur->right;      
                }    
                else
                {
                    /* Find the inorder predecessor of current */
                    auto node = cur->left;
                    while(node->right != NULL && node->right != cur)
                        node = node->right;

                    /* Make current as right child of its inorder predecessor */
                    if(node->right == NULL)
                    {
                        node->right = cur;
                        cur = cur->left;
                    }

                    /* Revert the changes made in if part to restore the original 
                       tree i.e., fix the right child of predecssor */   
                    else 
                    {
                        detect(broken, pre, cur);
                        node->right = NULL;
                        pre = cur;
                        cur = cur->right;      
                    }
                }
            }

            swap(broken.first->val, broken.second->val); // swap the fist and the last broken node
        }

        void detect(pair<TreeNode *, TreeNode *> &broken, TreeNode *pre, TreeNode *cur) {
            if(pre && pre->val > cur->val) {
                if(!broken.first) { // find the first broken node
                    broken.first = pre;
                }
                broken.second = cur;  // find the last broken node
            }
        }
};
