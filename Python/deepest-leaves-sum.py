# Time:  O(n)
# Space: O(w)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        curr = [root]
        while curr:
            prev, curr = curr, [child for p in curr for child in [p.left, p.right] if child]
        return sum(node.val for node in prev)
