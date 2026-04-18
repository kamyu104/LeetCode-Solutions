# Time:  O(n)
# Space: O(w)

# bfs
class Solution(object):
    def zigzagLevelSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        result = []
        q = [root]
        parity = 0
        while q:
            new_q = []
            total = 0
            stop = False
            for node in reversed(q):
                left, right = (node.left, node.right) if parity == 0 else (node.right, node.left)
                if left:
                    new_q.append(left)
                if right:
                    new_q.append(right)
                stop = stop or not left
                if not stop:
                    total += node.val
            result.append(total)
            q = new_q
            parity ^= 1
        return result
