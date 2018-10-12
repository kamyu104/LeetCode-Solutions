# Time:  O(n)
# Space: O(h), h is height of binary tree

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    maxSum = float("-inf")

    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        self.maxPathSumRecu(root)
        return self.maxSum

    def maxPathSumRecu(self, root):
        if root is None:
            return 0
        left = max(0, self.maxPathSumRecu(root.left))
        right = max(0, self.maxPathSumRecu(root.right))
        self.maxSum = max(self.maxSum, root.val + left + right)
        return root.val + max(left, right)

