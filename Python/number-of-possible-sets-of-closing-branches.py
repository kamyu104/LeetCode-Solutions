# Time:  O(r + 2^n * n^2)
# Space: O(n^3)

# graph, bitmasks, Floyd-Warshall algorithm, backtracking
class Solution(object):
    def numberOfSets(self, n, maxDistance, roads):
        """
        :type n: int
        :type maxDistance: int
        :type roads: List[List[int]]
        :rtype: int
        """
        def check(mask, dist):
            return all(dist[i][j] <= maxDistance for i in xrange(n) if mask&(1<<i) for j in xrange(i+1, n) if mask&(1<<j))

        def floydWarshall(dist, k):
            for i in xrange(len(dist)):
                for j in xrange(i+1, len(dist[i])):
                    dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])

        def backtracking(i, mask, dist):
            if i == n:
                result[0] += check(mask, dist)
                return
            for j in xrange(2):
                new_dist = [d[:] for d in dist]
                if j:
                    floydWarshall(new_dist, i)
                backtracking(i+1, mask|(j<<i), new_dist)
    
        dist = [[0 if u == v else float("inf") for v in xrange(n)] for u in xrange(n)]
        for u, v, w in roads:
            dist[u][v] = min(dist[u][v], w)
            dist[v][u] = min(dist[v][u], w)
        result = [0]
        backtracking(0, 0, [d[:] for d in dist])
        return result[0]
    

# Time:  O(r + 2^n * n^3)
# Space: O(n^2)
# bitmasks, Floyd-Warshall algorithm
class Solution2(object):
    def numberOfSets(self, n, maxDistance, roads):
        """
        :type n: int
        :type maxDistance: int
        :type roads: List[List[int]]
        :rtype: int
        """
        def check(mask, dist):
            return all(dist[i][j] <= maxDistance for i in xrange(n) if mask&(1<<i) for j in xrange(i+1, n) if mask&(1<<j))

        def floydWarshall(mask, dist):
            for k in xrange(len(dist[0])):
                if mask&(1<<k) == 0:
                    continue
                for i in xrange(len(dist)):
                    if mask&(1<<i) == 0:  # optional, to speed up performance
                        continue
                    for j in xrange(i+1, len(dist[i])):
                        if mask&(1<<j) == 0:  # optional, to speed up performance
                             continue
                        dist[j][i] = dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j])
            return check(mask, dist)

        dist = [[0 if u == v else float("inf") for v in xrange(n)] for u in xrange(n)]
        for u, v, w in roads:
            dist[u][v] = min(dist[u][v], w)
            dist[v][u] = min(dist[v][u], w)
        return sum(floydWarshall(mask, [d[:] for d in dist]) for mask in xrange(1<<n))
    
