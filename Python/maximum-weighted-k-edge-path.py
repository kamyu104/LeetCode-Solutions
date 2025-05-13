# Time:  O(k * e * t)
# Space: O(n * t)

# dp
class Solution(object):
    def maxWeight(self, n, edges, k, t):
        """
        :type n: int
        :type edges: List[List[int]]
        :type k: int
        :type t: int
        :rtype: int
        """
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        dp = [{0} for _ in xrange(n)]
        for _ in xrange(k):
            new_dp = [set() for _ in xrange(n)]
            for i in xrange(n):
                for c in dp[i]:
                    for j, w in adj[i]:
                        if c+w < t:
                            new_dp[j].add(c+w)
            dp = new_dp
        result = -1
        for x in dp:
            if x:
                result = max(result, max(x))
        return result
