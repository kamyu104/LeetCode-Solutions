# Time:  O(n)
# Space: O(h)

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        pass


import collections


# tree dp with stack
class Solution(object):
    def minimumFlips(self, root, result):
        """
        :type root: Optional[TreeNode]
        :type result: bool
        :rtype: int
        """
        INF = float("inf")
        OP = {
            2: lambda x, y: x or y,
            3: lambda x, y: x and y,
            4: lambda x, y: x^y ,
            5: lambda x, y: not x if x is not None else not y
        }
        
        def iter_dfs(root, result):
            ret = collections.defaultdict(lambda: INF)
            stk = [(1, (root, ret))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    node, ret = args
                    if not node:
                        ret[None] = 0 # null object pattern
                        continue
                    if node.left == node.right:
                        ret[True] = node.val^1
                        ret[False] = node.val^0
                        continue
                    ret1 = collections.defaultdict(lambda: INF)
                    ret2 = collections.defaultdict(lambda: INF)
                    stk.append((2, (node, ret1, ret2, ret)))
                    stk.append((1, (node.right, ret2)))
                    stk.append((1, (node.left, ret1)))
                elif step == 2:
                    node, ret1, ret2, ret = args
                    for k1, v1 in ret1.iteritems():
                        for k2, v2 in ret2.iteritems():
                            ret[OP[node.val](k1, k2)] = min(ret[OP[node.val](k1, k2)], v1+v2)
            return ret[result]

        return iter_dfs(root, result)


import collections


# tree dp with recursion
class Solution2(object):
    def minimumFlips(self, root, result):
        """
        :type root: Optional[TreeNode]
        :type result: bool
        :rtype: int
        """
        INF = float("inf")
        OP = {
            2: lambda x, y: x or y,
            3: lambda x, y: x and y,
            4: lambda x, y: x^y ,
            5: lambda x, y: not x if x is not None else not y
        }
        
        def dfs(node):
            if not node:
                return {None: 0}  # null object pattern
            if node.left == node.right:
                return {True: node.val^1, False: node.val^0}
            left = dfs(node.left)
            right = dfs(node.right)
            dp = collections.defaultdict(lambda: INF)
            for k1, v1 in left.iteritems():
                for k2, v2 in right.iteritems():
                    dp[OP[node.val](k1, k2)] = min(dp[OP[node.val](k1, k2)], v1+v2)
            return dp

        return dfs(root)[result]
