# Time:  O(nlogn)
# Space: O(w)

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# bfs, sort
class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        result = 0
        q = [root]
        while q:
            new_q = []
            for node in q:
                if node.left:
                    new_q.append(node.left)
                if node.right:
                    new_q.append(node.right)
            idx = range(len(q))
            idx.sort(key=lambda x: q[x].val)
            for i in xrange(len(q)):
                while idx[i] != i:
                    idx[idx[i]], idx[i] = idx[i], idx[idx[i]]
                    result += 1
            q = new_q
        return result
