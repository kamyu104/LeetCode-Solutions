# Time:  O(n)
# Space: O(h)

import collections


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# dfs solution
class Solution(object):
    def maxLevelSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(node, i, level_sums):
            if not node:
                return
            if i == len(level_sums):
                level_sums.append(0)
            level_sums[i] += node.val
            dfs(node.left, i+1, level_sums)
            dfs(node.right, i+1, level_sums)

        level_sums = []
        dfs(root, 0, level_sums)
        return level_sums.index(max(level_sums))+1

    
# Time:  O(n)
# Space: O(w)
# bfs solution
class Solution2(object):
    def maxLevelSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result, level, max_total = 0, 1, float("-inf")
        q = collections.deque([root])
        while q:
            total = 0
            for _ in xrange(len(q)):
                node = q.popleft()
                total += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if total > max_total:
                result, max_total = level, total
            level += 1
        return result
