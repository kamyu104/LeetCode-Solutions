# Time:  O(n)
# Space: O(h)

# Definition for a rope tree node.
class RopeTreeNode(object):
    def __init__(self, len=0, val="", left=None, right=None):
        pass


# binary tree
class Solution(object):
    def getKthCharacter(self, root, k):
        """
        :type root: Optional[RopeTreeNode]
        :type k: int
        :rtype: str
        """
        while root.len:
            l = max(root.left.len, len(root.left.val)) if root.left else 0
            if k <= l:
                root = root.left
            else:
                k -= l
                root = root.right
        return root.val[k-1]
