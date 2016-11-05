# Time:  O(h)
# Space: O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return root

        if root.val > key:
            root.left = deleteNode(root.left, key)
        elif root.val < key:
            root.right = deleteNode(root.right, key)
        else:
            if not root.left:
                right = root.right
                del root
                return right
            elif not root.right:
                left = root.left
                del root
                return left
            else:
                successor = root.right
                while successor.left:
                    successor = successor.left

                root.val = successor.val
                root.right = deleteNode(root.right, successor.val)

        return root
