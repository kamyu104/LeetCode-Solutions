# Time:  O(n)
# Space: O(h)

# Given a Binary Search Tree (BST),
# convert it to a Greater Tree such that every key of
# the original BST is changed to the original key plus sum of
# all keys greater than the original key in BST.
#
# Example:
#
# Input: The root of a Binary Search Tree like this:
#               5
#             /   \
#           2     13
#
# Output: The root of a Greater Tree like this:
#              18
#             /   \
#           20     13
          
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def convertBSTHelper(root, cur_sum):
            if not root:
                return cur_sum

            if root.right:
                cur_sum = convertBSTHelper(root.right, cur_sum)
            cur_sum += root.val
            root.val = cur_sum;
            if root.left:
                cur_sum = convertBSTHelper(root.left, cur_sum)
            return cur_sum

        convertBSTHelper(root, 0)
        return root
