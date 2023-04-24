# Time:  ctor:         O(|V| + |E|)
#        addEdge:      O(1)
#        shortestPath: O((|E| + |V|) * log|V|) = O(|E| * log|V|)
# Space: O(|E| + |V|) = O(|E|)

import heapq


# dijkstra's algorithm
class Graph(object):

    def __init__(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        """
        self.__adj = [[] for _ in xrange(n)]
        for edge in edges:
            self.addEdge(edge)

    def addEdge(self, edge):
        """
        :type edge: List[int]
        :rtype: None
        """
        u, v, w = edge
        self.__adj[u].append((v, w))

    def shortestPath(self, node1, node2):
        """
        :type node1: int
        :type node2: int
        :rtype: int
        """
        def dijkstra(adj, start, target):
            best = [float("inf")]*len(adj)
            best[start] = 0
            min_heap = [(best[start], start)]
            while min_heap:
                curr, u = heapq.heappop(min_heap)
                if curr > best[u]:
                    continue
                for v, w in adj[u]:                
                    if not (curr+w < best[v]):
                        continue
                    best[v] = curr+w
                    heapq.heappush(min_heap, (best[v], v))
            return best[target] if best[target] != float("inf") else -1

        return dijkstra(self.__adj, node1, node2)
