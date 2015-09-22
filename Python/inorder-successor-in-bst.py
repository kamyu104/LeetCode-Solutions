# Time:  O(h)
# Space: O(1)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        # If it has right subtree.
        if p and p.right:
            p = p.right
            while p.left:
                p = p.left
            return p

        # Search from root.
        successor = None
        while root and root != p:
            if root.val > p.val:
                successor = root
                root = root.left
            else:
                root = root.right

        return successor
