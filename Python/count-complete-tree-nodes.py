# Time:  O(h * h) = O((logn)^2)
# Space: O(1)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def height(root):
            h = -1
            while root:
                h += 1
                root = root.left
            return h

        result, h = 0, height(root)
        while root:
            if height(root.right) == h-1:
                result += 2**h
                root = root.right
            else:
                result += 2**(h-1)
                root = root.left
            h -= 1
        return result

    
# Time:  O(h * logn) = O((logn)^2)
# Space: O(1)
class Solution2(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def check(node, n):
            base = 1
            while base <= n:
                base <<= 1
            base >>= 2

            while base:
                if (n & base) == 0:
                    node = node.left
                else:
                    node = node.right
                base >>= 1
            return bool(node)

        if not root:
            return 0

        node, level = root, 0
        while node.left:
            node = node.left
            level += 1

        left, right = 2**level, 2**(level+1)-1
        while left <= right:
            mid = left+(right-left)//2
            if not check(root, mid):
                right = mid-1
            else:
                left = mid+1
        return right
