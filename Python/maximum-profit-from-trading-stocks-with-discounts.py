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
            ret = [collections.defaultdict(int) for _ in xrange(2)]
            stk = [(1, (0, ret))]
            while stk:
                step, args = stk.pop()
                if step == 1:
                    u, ret = args
                    dp = [collections.defaultdict(int) for _ in xrange(2)]
                    dp[0][0] = dp[1][0] = 0
                    stk.append((4, (u, dp, ret)))
                    stk.append((2, (u, dp, 0)))
                elif step == 2:
                    u, dp, i = args
                    if i == len(adj[u]):
                        continue
                    v = adj[u][i]
                    stk.append((2, (u, dp, i+1)))
                    new_ret = [collections.defaultdict(int) for _ in xrange(2)]
                    stk.append((3, (new_ret, dp)))
                    stk.append((1, (v, new_ret)))
                elif step == 3:
                    new_ret, dp = args
                    new_dp = [collections.defaultdict(int) for _ in xrange(2)]
                    for i in xrange(2):
                        for j1, v1 in dp[i].iteritems():
                            for j2, v2 in new_ret[i].iteritems():
                                if j1+j2 <= budget:
                                    new_dp[i][j1+j2] = max(new_dp[i][j1+j2], v1+v2)
                    dp[:] = new_dp
                elif step == 4:
                    u, dp, ret = args
                    for i in xrange(2):
                        for j, v in dp[0].iteritems():
                            ret[i][j] = max(ret[i][j], v)
                        cost = present[u]>>i
                        if cost > budget:
                            continue
                        profit = future[u]-cost
                        for j, v in dp[1].iteritems():
                            if j+cost <= budget:
                                ret[i][j+cost] = max(ret[i][j+cost], v+profit)
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
                res = dfs(v)
                new_dp = [collections.defaultdict(int) for _ in xrange(2)]
                for i in xrange(2):
                    for j1, v1 in dp[i].iteritems():
                        for j2, v2 in res[i].iteritems():
                            if j1+j2 <= budget:
                                new_dp[i][j1+j2] = max(new_dp[i][j1+j2], v1+v2)
                dp = new_dp
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
