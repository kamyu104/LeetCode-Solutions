# Time:  O(1)
# Space: O(h), h is height of binary tree

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator(object):
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = []
        self.cur = root

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return self.stack or self.cur

    # @return an integer, the next smallest number
    def next(self):
        while self.cur:
            self.stack.append(self.cur)
            self.cur = self.cur.left

        self.cur = self.stack.pop()
        node = self.cur
        self.cur = self.cur.right

        return node.val

