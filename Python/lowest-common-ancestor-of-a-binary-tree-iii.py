# Time:  O(h)
# Space: O(1)

# Definition for a Node.
class Node:
    def __init__(self, val):
        pass

class Solution(object):
    def lowestCommonAncestor(self, p, q):
        """
        :type node: Node
        :rtype: Node
        """
        a, b = p, q
        while a != b:
            a = a.parent if a else q
            b = b.parent if b else p
        return a


# Time:  O(h)
# Space: O(1)
class Solution2(object):
    def lowestCommonAncestor(self, p, q):
        """
        :type node: Node
        :rtype: Node
        """
        def depth(node):
            d = 0
            while node:
                node = node.parent
                d += 1
            return d
        
        p_d, q_d = depth(p), depth(q)
        while p_d > q_d:
            p = p.parent
            p_d -= 1
        while p_d < q_d:
            q = q.parent
            q_d -= 1
        while p != q:
            p = p.parent
            q = q.parent
        return p
