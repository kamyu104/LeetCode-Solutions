# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        MOD = 10**9+7

        def dijkstra(adj, start, target):
            best = collections.defaultdict(lambda:float("inf"))
            best[start] = 0
            min_heap = [(0, start)]
            dp = [0]*(len(adj))  # modified, add dp to keep number of ways
            dp[0] = 1
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if best[u] < curr:
                    continue
                if u == target:  # modified, early return
                    break
                for v, w in adj[u]:                
                    if v in best and best[v] <= curr+w:
                        if best[v] == curr+w:  # modified, update number of ways in this minimal time
                            dp[v] = (dp[v]+dp[u])%MOD
                        continue
                    dp[v] = dp[u]  # modified, init number of ways in this minimal time
                    best[v] = curr+w
                    heapq.heappush(min_heap, (curr+w, v))
            return dp[target]

        adj = [[] for i in xrange(n)]
        for u, v, w in roads:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return dijkstra(adj, 0, n-1)
