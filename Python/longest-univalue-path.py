# Time:  O(n)
# Space: O(h)

# Given a binary tree, find the length of the longest path
# where each node in the path has the same value. This path may or may not pass through the root.
#
# Note: The length of path between two nodes is represented by the number of edges between them.
#
# Example 1:
# Input:
#
#               5
#              / \
#             4   5
#            / \   \
#           1   1   5
# Output:
# 2
#
# Example 2:
# Input:
#
#               1
#              / \
#             4   5
#            / \   \
#           4   4   5
# Output:
# 2
#
# Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

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
