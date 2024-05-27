# Time:  O(n)
# Space: O(w)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# bfs
class Solution(object):
    def minimumLevel(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        q = [root]
        d = 1
        result = ((float("inf"), float("inf")))
        while q:
            new_q = []
            total = 0
            for u in q:
                if u.left:
                    new_q.append(u.left)
                if u.right:
                    new_q.append(u.right)
                total += u.val
            result = min(result, (total, d))
            q = new_q
            d += 1
        return result[-1]
