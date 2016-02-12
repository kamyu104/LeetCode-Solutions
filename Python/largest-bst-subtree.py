# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0

        max_size = [1]
        def largestBSTSubtreeHelper(root):
            if root is None or (root.left is None and root.right is None):
                return int(root is not None), root.val, root.val

            left_size, left_min, left_max = 0, root.val, root.val - 1
            if root.left is not None:
                left_size, left_min, left_max = largestBSTSubtreeHelper(root.left)
            
            right_size, right_min, right_max = 0, root.val + 1, root.val
            if root.right is not None:
                right_size, right_min, right_max = largestBSTSubtreeHelper(root.right)

            if (root.left is None or left_size > 0) and \
               (root.right is None or right_size > 0) and \
               left_max < root.val < right_min:
                max_size[0] = max(max_size[0], 1 + left_size + right_size)
                return 1 + left_size + right_size, left_min, right_max

            return 0, root.val, root.val

        largestBSTSubtreeHelper(root)
        return max_size[0]
