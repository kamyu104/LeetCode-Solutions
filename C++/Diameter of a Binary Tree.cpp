class Solution {
    public: 
    int ans=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHt= height(root->left);
        int rightHt= height(root->right);
        ans=max(leftHt+rightHt,ans);
        return max(leftHt,rightHt)+1;
    }
        int diameterOfBinaryTree(TreeNode* root) { 
            height(root);
            return ans;
        }
    };