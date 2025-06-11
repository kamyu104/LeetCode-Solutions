# Time:  O(n * b)
# Space: O(n + b)

import collections


# iterative dfs, tree dp
class Solution(object):
    def maxProfit(self, n, present, future, hierarchy, budget):
        """
        :type n: int
        :type present: List[int]
        :type future: List[int]
        :type hierarchy: List[List[int]]
        :type budget: int
        :rtype: int
        """
        def iter_dfs():
            ret = []
            stk = [(1, (0, ret))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, ret = args
                    ret[:] = [collections.defaultdict(int) for _ in xrange(2)]
                    ret[0][0] = ret[1][0] = 0
                    stk.append((4, (u, ret)))
                    stk.append((2, (u, 0, ret)))
                elif step == 2:
                    u, i, ret = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, i+1, ret)))
                    new_ret = []
                    stk.append((3, (new_ret, ret)))
                    stk.append((1, (v, new_ret)))
                elif step == 3:
                    new_ret, ret = args
                    for i in xrange(2):
                        for j1, v1 in ret[i].items():
                            for j2, v2 in new_ret[i].iteritems():
                                if j1+j2 <= budget:
                                    ret[i][j1+j2] = max(ret[i][j1+j2], v1+v2)
                elif step == 4:
                    u, ret = args
                    new_ret = [collections.defaultdict(int) for _ in xrange(2)]
                    for i in xrange(2):
                        for j, v in ret[0].iteritems():
                            new_ret[i][j] = max(new_ret[i][j], v)
                        cost = present[u]>>i
                        if cost > budget:
                            continue
                        profit = future[u]-cost
                        for j, v in ret[1].iteritems():
                            if j+cost <= budget:
                                new_ret[i][j+cost] = max(new_ret[i][j+cost], v+profit)
                    ret[:] = new_ret
            return max(ret[0].itervalues())

        adj = [[] for _ in xrange(n)]
        for u, v in hierarchy:
            adj[u-1].append(v-1)
        return iter_dfs()


# Time:  O(n * b)
# Space: O(n + b)
import collections


# dfs, tree dp
class Solution2(object):
    def maxProfit(self, n, present, future, hierarchy, budget):
        """
        :type n: int
        :type present: List[int]
        :type future: List[int]
        :type hierarchy: List[List[int]]
        :type budget: int
        :rtype: int
        """
        def dfs(u):
            dp = [collections.defaultdict(int) for _ in xrange(2)]
            dp[0][0] = dp[1][0] = 0
            for v in adj[u]:
                new_dp = dfs(v)
                for i in xrange(2):
                    for j1, v1 in dp[i].items():
                        for j2, v2 in new_dp[i].iteritems():
                            if j1+j2 <= budget:
                                dp[i][j1+j2] = max(dp[i][j1+j2], v1+v2)
            result = [collections.defaultdict(int) for _ in xrange(2)]
            for i in xrange(2):
                for j, v in dp[0].iteritems():
                    result[i][j] = max(result[i][j], v)
                cost = present[u]>>i
                if cost > budget:
                    continue
                profit = future[u]-cost
                for j, v in dp[1].iteritems():
                    if j+cost <= budget:
                        result[i][j+cost] = max(result[i][j+cost], v+profit)
            return result  # result[i][j]: max profit for budget j with i discount

        adj = [[] for _ in xrange(n)]
        for u, v in hierarchy:
            adj[u-1].append(v-1)
        return max(dfs(0)[0].itervalues())
