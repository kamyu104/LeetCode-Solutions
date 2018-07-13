# Time:  O(h)
# Space: O(1)

# Given the root node of a binary search tree (BST) and
# a value to be inserted into the tree, insert the value into the BST.
# Return the root node of the BST after the insertion. It is guaranteed
# that the new value does not exist in the original BST.
#
# Note that there may exist multiple valid ways for the insertion,
# as long as the tree remains a BST after insertion. You can return any of them.
#
# For example, 
#
# Given the tree:
#         4
#        / \
#       2   7
#      / \
#     1   3
# And the value to insert: 5
# You can return this binary search tree:
#
#          4
#        /   \
#       2     7
#      / \   /
#     1   3 5
# This tree is also valid:
#
#          5
#        /   \
#       2     7
#      / \   
#     1   3
#          \
#           4


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        curr, parent = root, None
        while curr:
            parent = curr
            if val <= curr.val:
                curr = curr.left
            else:
                curr = curr.right
        if not parent:
            root = TreeNode(val)
        elif val <= parent.val:
            parent.left = TreeNode(val)
        else:
            parent.right = TreeNode(val)
        return root


# Time:  O(h)
# Space: O(h)
class Solution2(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root:
            root = TreeNode(val)
        else:
            if val <= root.val:
                root.left = self.insertIntoBST(root.left, val)
            else:
                root.right = self.insertIntoBST(root.right, val)
        return root
