# Time:  O((|E| + |V|) * log|V|)
# Space: O(|E| + |V|)

# There are N network nodes, labelled 1 to N.
#
# Given times, a list of travel times as directed edges times[i] = (u, v, w),
# where u is the source node, v is the target node,
# and w is the time it takes for a signal to travel from source to target.
#
# Now, we send a signal from a certain node K.
# How long will it take for all nodes to receive the signal? If it is impossible, return -1.
#
# Note:
# - N will be in the range [1, 100].
# - K will be in the range [1, N].
# - The length of times will be in the range [1, 6000].
# - All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

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
 
