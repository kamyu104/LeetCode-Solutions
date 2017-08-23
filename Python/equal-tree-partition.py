# Time:  O(n)
# Space: O(n)

# Given a binary tree with n nodes, your task is to check 
# if it's possible to partition the tree to two trees which have the equal sum 
# of values after removing exactly one edge on the original tree.
#
# Example 1:
# Input:     
#     5
#    / \
#   10 10
#     /  \
#    2   3
#
# Output: True
# Explanation: 
#     5
#    / 
#   10
#     
# Sum: 15
#
#    10
#   /  \
#  2    3
#
# Sum: 15
# Example 2:
# Input:     
#     1
#    / \
#   2  10
#     /  \
#    2   20
#
# Output: False
# Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
# Note:
# The range of tree node value is in the range of [-100000, 100000].
# 1 <= n <= 10000

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def checkEqualTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def getSumHelper(node, lookup):
            if not node:
                return 0
            total = node.val + \
                    getSumHelper(node.left, lookup) + \
                    getSumHelper(node.right, lookup)
            lookup[total] += 1
            return total

        lookup = collections.defaultdict(int)
        total = getSumHelper(root, lookup)
        if total == 0:
            return lookup[total] > 1
        return total%2 == 0 and (total/2) in lookup
