# Time:  O(n)
# Space: O(logn)
# 
# Given a binary tree, determine if it is a valid binary search tree (BST).
# 
# Assume a BST is defined as follows:
# 
# The left subtree of a node contains only nodes with keys less than the node's key.
# The right subtree of a node contains only nodes with keys greater than the node's key.
# Both the left and right subtrees must also be binary search trees.
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def isValidBST(self, root):
        return self.isValidBSTRecu(root, float("-inf"), float("inf"))
    
    def isValidBSTRecu(self, root, low, high):
        if root is None:
            return True
        
        return low < root.val and root.val < high \
            and self.isValidBSTRecu(root.left, low, root.val) \
            and self.isValidBSTRecu(root.right, root.val, high)
        
if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    print Solution().isValidBST(root)