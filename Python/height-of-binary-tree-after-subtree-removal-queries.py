# Time:  O(n)
# Space: O(n)

import collections


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


# iterative dfs
class Solution(object):
    def treeQueries(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        """
        def iter_dfs(root):
            top = collections.defaultdict(lambda: [0]*2)
            depth, height = {}, {}
            stk = [(1, (root, 0))]
            while stk:
                step, (curr, d) = stk.pop()
                if step == 1:
                    if not curr:
                        continue
                    stk.append((2, (curr, d)))
                    stk.append((1, (curr.right, d+1)))
                    stk.append((1, (curr.left, d+1)))
                elif step == 2:
                    h = 1+max((height[curr.left.val] if curr.left else 0), 
                              (height[curr.right.val] if curr.right else 0))
                    if h > top[d][0]:
                        top[d][0], top[d][1] = h, top[d][0]
                    elif h > top[d][1]:
                        top[d][1] = h
                    depth[curr.val], height[curr.val] = d, h
            return top, depth, height

        top, depth, height = iter_dfs(root)
        return [(depth[q]-1)+(top[depth[q]][0] if height[q] != top[depth[q]][0] else top[depth[q]][1]) for q in queries]


# Time:  O(n)
# Space: O(n)
import collections


# dfs
class Solution2(object):
    def treeQueries(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        """
        def dfs(curr, d):
            if not curr:
                return 0
            h = 1+max(dfs(curr.left, d+1), dfs(curr.right, d+1))
            if h > top[d][0]:
                top[d][0], top[d][1] = h, top[d][0]
            elif h > top[d][1]:
                top[d][1] = h
            depth[curr.val], height[curr.val] = d, h
            return h
        
        top = collections.defaultdict(lambda: [0]*2)
        depth, height = {}, {}
        dfs(root, 0)
        return [(depth[q]-1)+(top[depth[q]][0] if height[q] != top[depth[q]][0] else top[depth[q]][1]) for q in queries]
