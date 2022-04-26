# Time:  O(n^2 * 2^n)
# Space: O(n * 2^n)

# bfs
class Solution(object):
    def maximumCost(self, n, highways, k):
        """
        :type n: int
        :type highways: List[List[int]]
        :type k: int
        :rtype: int
        """
        if k+1 > n:
            return -1
        adj = [[] for _ in xrange(n)]
        for c1, c2, t in highways:
            adj[c1].append((c2, t))
            adj[c2].append((c1, t))
        result = -1
        q = [(u, 1<<u, 0) for u in xrange(n)]
        while q:
            new_q = []
            for u, mask, total in q:
                if bin(mask).count('1') == k+1:
                    result = max(result, total)
                for v, t in adj[u]:
                    if mask&(1<<v) == 0:
                        new_q.append((v, mask|(1<<v), total+t))
            q = new_q
        return result


# Time:  O(n^2 * 2^n)
# Space: O(n * 2^n)
import itertools


# combination, dp
class Solution(object):
    def maximumCost(self, n, highways, k):
        """
        :type n: int
        :type highways: List[List[int]]
        :type k: int
        :rtype: int
        """
        if k+1 > n:
            return -1
        adj = [[] for _ in xrange(n)]
        for c1, c2, t in highways:
            adj[c1].append((c2, t))
            adj[c2].append((c1, t))
        dp = [[0, []] for _ in xrange((1<<n))]
        for i in xrange(n):
            dp[1<<i][1].append(i)
        result = -1
        for cnt in xrange(1, n+1):
            for choice in itertools.combinations(xrange(n), cnt):
                mask = reduce(lambda x, y:x|(1<<y), choice, 0)
                for u in dp[mask][1]:
                    for v, t in adj[u]:
                        if mask&(1<<v):
                            continue
                        new_mask = mask|(1<<v)
                        if dp[mask][0]+t < dp[new_mask][0]:
                            continue
                        dp[new_mask][0] = dp[mask][0]+t
                        dp[new_mask][1].append(v)
                        if bin(mask).count('1') == k:
                            result = max(result, dp[new_mask][0])
        return result
