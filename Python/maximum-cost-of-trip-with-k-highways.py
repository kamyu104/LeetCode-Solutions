# Time:  O(n^2 * 2^n)
# Space: O(n * 2^n)

import itertools


# combination based dp
class Solution(object):
    def maximumCost(self, n, highways, k):
        """
        :type n: int
        :type highways: List[List[int]]
        :type k: int
        :rtype: int
        """
        if k+1 > n:  # optionally optimize
            return -1
        adj = [[] for _ in xrange(n)]
        for c1, c2, t in highways:
            adj[c1].append((c2, t))
            adj[c2].append((c1, t))
        result = -1 if k != 1 else 0
        dp = [[0, []] for _ in xrange((1<<n))]
        for i in xrange(n):
            dp[1<<i][1].append(i)
        for cnt in xrange(1, n+1):
            for choice in itertools.combinations(xrange(n), cnt):
                mask = reduce(lambda x, y:x|(1<<y), choice, 0)
                total, lasts = dp[mask]
                for u in lasts:
                    for v, t in adj[u]:
                        if mask&(1<<v):
                            continue
                        new_mask = mask|(1<<v)
                        if total+t < dp[new_mask][0]:
                            continue
                        if total+t == dp[new_mask][0]:
                            dp[new_mask][1].append(v)
                            continue
                        dp[new_mask][0] = total+t
                        dp[new_mask][1] = [v]
                        if bin(mask).count('1') == k:
                            result = max(result, dp[new_mask][0])
        return result


# Time:  O(n^2 * 2^n)
# Space: O(n * 2^n)
# bfs based dp
class Solution2(object):
    def maximumCost(self, n, highways, k):
        """
        :type n: int
        :type highways: List[List[int]]
        :type k: int
        :rtype: int
        """
        if k+1 > n:  # required to optimize, otherwise, TLE or MLE
            return -1
        adj = [[] for _ in xrange(n)]
        for c1, c2, t in highways:
            adj[c1].append((c2, t))
            adj[c2].append((c1, t))
        result = -1
        dp = [(u, 1<<u, 0) for u in xrange(n)]
        while dp:
            new_dp = []
            for u, mask, total in dp:
                if bin(mask).count('1') == k+1:
                    result = max(result, total)
                for v, t in adj[u]:
                    if mask&(1<<v) == 0:
                        new_dp.append((v, mask|(1<<v), total+t))
            dp = new_dp
        return result
