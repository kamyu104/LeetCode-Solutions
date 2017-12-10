# Time:  O(n)
# Space: O(n)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def traverse(node, neighbors, leaves):
            if not node:
                return
            if not node.left and not node.right:
                leaves.add(node.val)
                return
            if node.left:
                neighbors[node.val].append(node.left.val)
                neighbors[node.left.val].append(node.val)
                traverse(node.left, neighbors, leaves)
            if node.right:
                neighbors[node.val].append(node.right.val)
                neighbors[node.right.val].append(node.val)
                traverse(node.right, neighbors, leaves)
        
        neighbors, leaves = collections.defaultdict(list), set()
        traverse(root, neighbors, leaves)
        q, lookup = [k], set([k])
        while q:
            next_q = []
            for u in q:
                if u in leaves:
                    return u
                for v in neighbors[u]:
                    if v in lookup:
                        continue
                    lookup.add(v)
                    next_q.append(v)
            q = next_q
        return 0
