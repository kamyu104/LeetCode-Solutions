# Time:  O(n)
# Space: O(h), h is height of binary tree

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        return self.sumNumbersRecu(root, 0)

    def sumNumbersRecu(self, root, num):
        if root is None:
            return 0

        if root.left is None and root.right is None:
            return num * 10 + root.val

        return self.sumNumbersRecu(root.left, num * 10 + root.val) + self.sumNumbersRecu(root.right, num * 10 + root.val)

