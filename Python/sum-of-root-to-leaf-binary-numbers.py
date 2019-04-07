# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sumRootToLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        M = 10**9 + 7
        def sumRootToLeafHelper(root, val):
            if not root:
                return 0
            val = (val*2 + root.val) % M
            if not root.left and not root.right:
                return val
            return (sumRootToLeafHelper(root.left, val) +
                    sumRootToLeafHelper(root.right, val)) % M
        
        return sumRootToLeafHelper(root, 0)
