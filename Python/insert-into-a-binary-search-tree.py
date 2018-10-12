# Time:  O(h)
# Space: O(1)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        curr, parent = root, None
        while curr:
            parent = curr
            if val <= curr.val:
                curr = curr.left
            else:
                curr = curr.right
        if not parent:
            root = TreeNode(val)
        elif val <= parent.val:
            parent.left = TreeNode(val)
        else:
            parent.right = TreeNode(val)
        return root


# Time:  O(h)
# Space: O(h)
class Solution2(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root:
            root = TreeNode(val)
        else:
            if val <= root.val:
                root.left = self.insertIntoBST(root.left, val)
            else:
                root.right = self.insertIntoBST(root.right, val)
        return root

