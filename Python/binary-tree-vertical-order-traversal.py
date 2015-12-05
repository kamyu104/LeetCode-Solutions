# Time:  O(n)
# Space: O(n)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# BFS + hash solution.
class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        lookup = collections.defaultdict(list)
        min_idx = float("inf")
        max_idx = float("-inf")
        
        pre_level = [(root, 0)]
        while pre_level:
            cur_level = []
            for n, i in pre_level:
                min_idx, max_idx = min(min_idx, i), max(max_idx, i)
                lookup[i] += [n.val]
                if n.left:
                    cur_level.append((n.left, i - 1))
                if n.right:
                    cur_level.append((n.right, i + 1))
            pre_level = cur_level

        res = []
        for i in xrange(min_idx, max_idx + 1):
            if lookup[i]:
                res.append(lookup[i])
        return res
            
