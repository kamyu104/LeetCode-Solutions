# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sumEvenGrandparent(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def sumEvenGrandparentHelper(root, p, gp):
            return sumEvenGrandparentHelper(root.left, root.val, p) + \
                   sumEvenGrandparentHelper(root.right, root.val, p) + \
                   (root.val if gp is not None and gp % 2 == 0 else 0) if root else 0

        return sumEvenGrandparentHelper(root, None, None)
