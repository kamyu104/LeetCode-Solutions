# Time:  O(n)
# Space: O(h)

# Given a n-ary tree, find its maximum depth.
#
# The maximum depth is the number of nodes along the longest path
# from the root node down to the farthest leaf node.
#
# For example, given a 3-ary tree:
#
# We should return its max depth, which is 3.
#
# Note:
# - The depth of the tree is at most 1000.
# - The total number of nodes is at most 5000.

# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0
        depth = 0
        for child in root.children:
            depth = max(depth, self.maxDepth(child))
        return 1+depth
