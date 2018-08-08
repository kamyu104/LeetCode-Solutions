# Time:  O((|E| + |V|) * log|V|) = O(|E| * log|V|),
#        if we can further to use Fibonacci heap, it would be O(|E| + |V| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

# Starting with an undirected graph (the "original graph")
# with nodes from 0 to N-1, subdivisions are made to some of the edges.
# The graph is given as follows: edges[k] is a list of integer pairs
# (i, j, n) such that (i, j) is an edge of the original graph,
#
# and n is the total number of new nodes on that edge. 
#
# Then, the edge (i, j) is deleted from the original graph,
# n new nodes (x_1, x_2, ..., x_n) are added to the original graph,
#
# and n+1 new edges (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j)
# are added to the original graph.
#
# Now, you start at node 0 from the original graph, and in each move,
# you travel along one edge. 
#
# Return how many nodes you can reach in at most M moves.
#
# Example 1:
#
# Input: edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
# Output: 13
# Explanation: 
# The nodes that are reachable in the final graph after M = 6 moves are indicated below.
#
# Example 2:
#
# Input: edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
# Output: 23
#
# Note:
# - 0 <= edges.length <= 10000
# - 0 <= edges[i][0] < edges[i][1] < N
# - There does not exist any i != j for which
#   edges[i][0] == edges[j][0] and edges[i][1] == edges[j][1].
# - The original graph has no parallel edges.
# - 0 <= edges[i][2] <= 10000
# - 0 <= M <= 10^9
# - 1 <= N <= 3000

import collections
import heapq

class Solution(object):
    def reachableNodes(self, edges, M, N):
        """
        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        adj = [[] for _ in xrange(N)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        min_heap = [(0, 0)]
        best = collections.defaultdict(lambda: float("inf"))
        best[0] = 0
        count = collections.defaultdict(lambda: collections.defaultdict(int))
        result = 0
        while min_heap:
            curr_total, u = heapq.heappop(min_heap)  # O(|V|*log|V|) in total
            if best[u] < curr_total:
                continue
            result += 1
            for v, w in adj[u]:
                count[u][v] = min(w, M-curr_total)
                next_total = curr_total+w+1
                if next_total <= M and next_total < best[v]:
                    best[v] = next_total
                    heapq.heappush(min_heap, (next_total, v))  # binary heap O(|E|*log|V|) in total
                                                               # Fibonacci heap O(|E|) in total
        for u, v, w in edges:
            result += min(w, count[u][v]+count[v][u])
        return result
