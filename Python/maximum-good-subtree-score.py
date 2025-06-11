# Time:  O(n * (2^10)^2)
# Space: O(2^10)

import collections


# bitmasks, iterative dfs, tree dp
class Solution(object):
    def goodSubtreeSum(self, vals, par):
        """
        :type vals: List[int]
        :type par: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def get_mask(x):
            mask = 0
            while x:
                x, d = divmod(x, 10)
                if mask&(1<<d):
                    return -1
                mask |= 1<<d
            return mask

        def iter_dfs():
            result = 0
            ret = collections.defaultdict(int)
            stk = [(1, (0, ret))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, ret = args
                    ret[0] = 0
                    mask = get_mask(vals[u])
                    if mask != -1:
                        ret[mask] = vals[u]
                    stk.append((4, (u, ret)))
                    stk.append((2, (u, 0, ret)))
                elif step == 2:
                    u, i, ret = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, i+1, ret)))
                    new_ret = collections.defaultdict(int)
                    stk.append((3, (new_ret, ret)))
                    stk.append((1, (v, new_ret)))
                elif step == 3:
                    new_ret, ret = args
                    for m1, v1 in ret.items():
                        for m2, v2 in new_ret.iteritems():
                            if m1&m2:
                                continue
                            ret[m1|m2] =  max(ret[m1|m2], v1+v2)
                elif step == 4:
                    u, ret = args
                    result = (result+max(ret.itervalues()))%MOD
            return result

        adj = [[] for _ in xrange(len(vals))]
        for u in xrange(1, len(par)):
            adj[par[u]].append(u)
        return iter_dfs()


# Time:  O(n * (2^10)^2)
# Space: O(2^10)
import collections


# bitmasks, dfs, tree dp
class Solution2(object):
    def goodSubtreeSum(self, vals, par):
        """
        :type vals: List[int]
        :type par: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def get_mask(x):
            mask = 0
            while x:
                x, d = divmod(x, 10)
                if mask&(1<<d):
                    return -1
                mask |= 1<<d
            return mask

        def dfs(u):
            dp = collections.defaultdict(int)
            dp[0] = 0
            mask = get_mask(vals[u])
            if mask != -1:
                dp[mask] = vals[u]
            for v in adj[u]:
                new_dp = dfs(v)
                for m1, v1 in dp.items():
                    for m2, v2 in new_dp.iteritems():
                        if m1&m2:
                            continue
                        dp[m1|m2] =  max(dp[m1|m2], v1+v2)
            result[0] = (result[0]+max(dp.itervalues()))%MOD
            return dp

        adj = [[] for _ in xrange(len(vals))]
        for u in xrange(1, len(par)):
            adj[par[u]].append(u)
        result = [0]
        dfs(0)
        return result[0]
