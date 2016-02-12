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
        if not root:
            return 0

        max_size = [1]
        def largestBSTSubtreeHelper(root):
            if root.left is None and root.right is None:
                return 1, root.val, root.val

            if root.left is None:
                size, min_val, max_val = largestBSTSubtreeHelper(root.right)
                if size > 0 and root.val < min_val:
                    max_size[0] = max(max_size[0], 1 + size)
                    return 1 + size, root.val, max_val
            elif root.right is None:
                size, min_val, max_val = largestBSTSubtreeHelper(root.left)
                if size > 0 and max_val < root.val:
                    max_size[0] = max(max_size[0], 1 + size)
                    return 1 + size, min_val, root.val
            else:
                left_size, left_min, left_max = largestBSTSubtreeHelper(root.left)
                right_size, right_min, right_max = largestBSTSubtreeHelper(root.right)
                if left_max < root.val < right_min and left_size > 0 and right_size > 0:
                    size = 1 + left_size + right_size
                    max_size[0] = max(max_size[0], size)
                    return size, left_min, right_max

            return 0, root.val, root.val

        largestBSTSubtreeHelper(root)
        return max_size[0]
