# Time:  O(h)
# Space: O(1)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        gap = float("inf")
        closet = float("inf")
        while root:
            if abs(root.val - target) < gap:
                gap = abs(root.val - target)
                closet = root
            if target == root.val:
                break
            elif target < root.val:
                root = root.left
            else:
                root = root.right
        return closet.val
