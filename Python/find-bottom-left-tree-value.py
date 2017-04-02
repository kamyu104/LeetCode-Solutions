# Time:  O(n)
# Space: O(h)

# Given a binary tree, find the leftmost value in the last row of the tree.
#
# Example 1:
# Input:
#
#     2
#   / \
#   1   3
#
# Output:
# 1
# Example 2: 
# Input:
#
#         1
#       / \
#       2   3
#      /   / \
#     4   5   6
#       /
#       7
#
# Output:
# 7
# Note: You may assume the tree (i.e., the given root node) is not NULL.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def findBottomLeftValueHelper(root, curr_depth, max_depth, bottom_left_value):
            if not root:
                return max_depth, bottom_left_value
            if not root.left and not root.right and curr_depth+1 > max_depth:
                return curr_depth+1, root.val
            max_depth, bottom_left_value = findBottomLeftValueHelper(root.left, curr_depth+1, max_depth, bottom_left_value)
            max_depth, bottom_left_value = findBottomLeftValueHelper(root.right, curr_depth+1, max_depth, bottom_left_value)
            return max_depth, bottom_left_value

        result, max_depth = 0, 0
        return findBottomLeftValueHelper(root, 0, max_depth, result)[1]


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        queue = [root]
        for node in queue:
            queue += filter(None, (node.right, node.left))
        return node.val
