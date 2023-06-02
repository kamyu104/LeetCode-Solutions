# Time:  O(n * k + (e * k) * log(n * k))
# Space: O(n * k + e)

import heapq


# dijkstra's algorithm
class Solution(object):
    def shortestPathWithHops(self, n, edges, s, d, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type s: int
        :type d: int
        :type k: int
        :rtype: int
        """
        def modified_dijkstra():
            best = [[float("inf")]*(k+1) for _ in xrange(len(adj))]
            best[s][0] = 0
            min_heap = [(best[s][0], s, 0)]
            while min_heap:
                curr, u, cnt = heapq.heappop(min_heap)
                if curr > best[u][cnt]:
                    continue
                if u == d:
                    return curr
                for v, w in adj[u]:
                    if curr+w < best[v][cnt]:
                        best[v][cnt] = curr+w
                        heapq.heappush(min_heap, (best[v][cnt], v, cnt))
                    if cnt+1 <= k and curr < best[v][cnt+1]:
                        best[v][cnt+1] = curr
                        heapq.heappush(min_heap, (best[v][cnt+1], v, cnt+1))
            return -1
        
        adj = [[] for _ in xrange(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return modified_dijkstra()
