# Time:  O(h)
# Space: O(1)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def insertIntoMaxTree(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root:
            return TreeNode(val)

        if val > root.val:
            node = TreeNode(val)
            node.left = root
            return node
        
        curr = root
        while curr.right and curr.right.val > val:
            curr = curr.right
        node = TreeNode(val)
        curr.right, node.left = node, curr.right
        return root
