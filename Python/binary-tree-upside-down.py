# Time:  O(n)
# Space: O(1)
#
# Given a binary tree where all the right nodes are either leaf nodes with a sibling 
# (a left node that shares the same parent node) or empty, flip it upside down and 
# turn it into a tree where the original right nodes turned into left leaf nodes. 
# Return the new root.
# 
# For example:
# Given a binary tree {1,2,3,4,5},
# 
#     1
#    / \
#   2   3
#  / \
# 4   5
# 
# return the root of the binary tree [4,5,2,#,#,3,1].
# 
#    4
#   / \
#  5   2
#     / \
#    3   1  
#

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return root of the upside down tree
    def upsideDownBinaryTree(self, root):
        p, parent, parent_right = root, None, None
        
        while p:
            left = p.left
            p.left = parent_right
            parent_right = p.right
            p.right = parent
            parent = p
            p = left
            
        return parent

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param root, a tree node
    # @return root of the upside down tree
    def upsideDownBinaryTree(self, root):
        return self.upsideDownBinaryTreeRecu(root, None)
    
    def upsideDownBinaryTreeRecu(self, p, parent):
        if p is None:
            return parent
        
        root = self.upsideDownBinaryTreeRecu(p.left, p)
        if parent:
            p.left = parent.right
        else:
            p.left = None
        p.right = parent
        
        return root