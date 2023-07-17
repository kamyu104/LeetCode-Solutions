# Time:  O(n)
# Space: O(h)

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# dfs
class Solution(object):
    def heightOfTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        result = -1
        stk = [(root, 0)]
        while stk:
            u, d = stk.pop()
            result = max(result, d)
            if u.right and u.right.left != u:
                stk.append((u.right, d+1))
            if u.left and u.left.right != u:
                stk.append((u.left, d+1))
        return result


# Time:  O(n)
# Space: O(w)
# bfs
class Solution2(object):
    def heightOfTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        result = -1
        q = [root]
        while q:
            new_q = []
            for u in q:
                if u.left and u.left.right != u:
                    new_q.append(u.left)
                if u.right and u.right.left != u:
                    new_q.append(u.right)
            q = new_q
            result += 1
        return result
