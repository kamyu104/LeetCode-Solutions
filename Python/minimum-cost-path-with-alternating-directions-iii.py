# Time:  O(m * n * log(m * n))
# Space: O(m * n)

# dijkstra's algorithm
class Solution(object):
    def minCost(self, m, n, penalty):
        """
        :type m: int
        :type n: int
        :type penalty: List[List[int]]
        :rtype: int
        """
        DIRECTIONS = ((1, 1, 0), (1, 0, 1), (0, -1, 0), (0, 0, -1))
        dist = [[[float("inf")]*n for _ in xrange(m)] for _ in xrange(2)]
        np = ni = nj = 0
        dist[np][ni][nj] = (ni+1)*(nj+1)
        min_heap = [(dist[np][ni][nj], np, ni, nj)]
        while min_heap:
            w, p, i, j = heapq.heappop(min_heap)
            if w != dist[p][i][j]:
                continue
            if (i, j) == (m-1, n-1):
                return w
            if w+penalty[i][j] < dist[p^1][i][j]:
                dist[p^1][i][j] = w+penalty[i][j]
                heapq.heappush(min_heap, (dist[p^1][i][j], p^1, i, j))
            for dp, di, dj in DIRECTIONS:
                np, ni, nj = p^1, i+di, j+dj
                if not (0 <= ni < m and 0 <= nj < n and w+(ni+1)*(nj+1)+(penalty[i][j] if np != dp else 0) < dist[np][ni][nj]):
                    continue
                dist[np][ni][nj] = w+(ni+1)*(nj+1)+(penalty[i][j] if np != dp else 0)
                heapq.heappush(min_heap, (dist[np][ni][nj], np, ni, nj))
        return -1
