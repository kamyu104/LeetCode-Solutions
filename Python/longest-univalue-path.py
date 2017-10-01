# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = [0]
        def dfs(node):
            if not node:
                return 0
            left, right = dfs(node.left), dfs(node.right)
            left = (left+1) if node.left and node.left.val == node.val else 0
            right = (right+1) if node.right and node.right.val == node.val else 0
            result[0] = max(result[0], left+right)
            return max(left, right)
        
        dfs(root)
        return result[0]
