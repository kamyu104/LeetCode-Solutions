# Time:  O(n)
# Space: O(w)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isEvenOddTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        q = [root]
        is_odd = False
        while q:
            new_q = []
            prev = None
            for node in q:
                if is_odd:
                    if node.val%2 or (prev and prev.val <= node.val):
                        return False
                else:
                    if not node.val%2 or (prev and prev.val >= node.val):
                        return False
                if node.left:
                    new_q.append(node.left)
                if node.right:
                    new_q.append(node.right)
                prev = node
            q = new_q
            is_odd = not is_odd
        return True
