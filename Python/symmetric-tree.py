# Time:  O(n)
# Space: O(h), h is height of binary tree
# Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# Iterative solution
class Solution(object):
    # @param root, a tree node
    # @return a boolean
    def isSymmetric(self, root):
        if root is None:
            return True
        stack = []
        stack.append(root.left)
        stack.append(root.right)

        while stack:
            p, q = stack.pop(), stack.pop()

            if p is None and q is None:
                continue

            if p is None or q is None or p.val != q.val:
                return False

            stack.append(p.left)
            stack.append(q.right)

            stack.append(p.right)
            stack.append(q.left)

        return True

# Recursive solution
class Solution2(object):
    # @param root, a tree node
    # @return a boolean
    def isSymmetric(self, root):
        if root is None:
            return True

        return self.isSymmetricRecu(root.left, root.right)

    def isSymmetricRecu(self, left, right):
        if left is None and right is None:
            return True
        if left is None or right is None or left.val != right.val:
            return False
        return self.isSymmetricRecu(left.left, right.right) and self.isSymmetricRecu(left.right, right.left)

