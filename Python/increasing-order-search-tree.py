# Time:  O(n)
# Space: O(h)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def increasingBSTHelper(root, tail):
            if not root:
                return tail
            result = increasingBSTHelper(root.left, root)
            root.left = None
            root.right = increasingBSTHelper(root.right, tail)
            return result
        return increasingBSTHelper(root, None)

