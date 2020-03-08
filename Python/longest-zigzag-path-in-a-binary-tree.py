# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def longestZigZag(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node, result):
            if not node:
                return [-1, -1]
            left, right = dfs(node.left, result), dfs(node.right, result)
            result[0] = max(result[0], left[1]+1, right[0]+1)
            return [left[1]+1, right[0]+1]

        result = [0]
        dfs(root, result)
        return result[0]
