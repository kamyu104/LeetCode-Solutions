# Time:  O(26^3 + n)
# Space: O(26^2)

# Floyd-Warshall algorithm 
class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        INF = float("inf")
        def floydWarshall(dist):
            for k in xrange(len(dist)):
                for i in xrange(len(dist)):
                    for j in xrange(len(dist[i])):
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

        dist = [[0 if u == v else INF for v in xrange(26)] for u in xrange(26)]
        for i in xrange(len(original)):
            u, v = ord(original[i])-ord('a'), ord(changed[i])-ord('a')
            dist[u][v] = min(dist[u][v], cost[i])
        floydWarshall(dist)
        result = sum(dist[ord(source[i])-ord('a')][ord(target[i])-ord('a')] for i in xrange(len(source)))
        return result if result != INF else -1
