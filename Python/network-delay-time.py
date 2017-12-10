# Time:  O((|E| + |V|) * log|V|)
# Space: O(|E| + |V|)

# Dijkstra's algorithm
class Solution(object):
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        adj = [[] for _ in xrange(N)]
        for u, v, w in times:
            adj[u-1].append((v-1, w))
            
        result = 0
        lookup = set()
        min_heap = [(0, K-1)]
        while min_heap and len(lookup) != N:
            result, u = heapq.heappop(min_heap)
            lookup.add(u)
            for v, w in adj[u]:
                if v in lookup: continue
                heapq.heappush(min_heap, (result+w, v))
        return result if len(lookup) == N else -1
 
