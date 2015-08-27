# Time:  O(n)
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
        closet = root
        while root:
            if target == root.val:
                return root.val
            elif target < root.val:
                if abs(root.val - target) < gap:
                    gap = abs(root.val - target)
                    closet = root
                root = root.left
            else:
                if abs(root.val - target) < gap:
                    gap = abs(root.val - target)
                    closet = root
                root = root.right
        return closet.val
