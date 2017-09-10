# Time:  O(t * (logt + m * n)), t is the number of trees
# Space: O(t + m * n)

class Solution(object):
    def cutOffTree_TLE(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
        
        def minStep(forest, start, tree, m, n):
            step = 0
            lookup = set()
            q = collections.deque()
            q.append(start);
            lookup.add(start[0]*n+start[1])
            while q:
                size = len(q)
                for _ in xrange(size):
                    curr = q.popleft()
                    if curr == tree[1]:
                        return step
                    for direction in directions:
                        i, j = curr[0]+direction[0], curr[1]+direction[1]
                        if not (0 <= i < m and 0 <= j < n and forest[i][j] and (i*n+j) not in lookup):
                            continue
                        q.append((i, j))
                        lookup.add(i*n+j)
                step += 1
            return -1
        
        m, n = len(forest), len(forest[0])
        min_heap = []
        for i in xrange(m):
            for j in xrange(n):
                if forest[i][j] > 1:
                    heapq.heappush(min_heap, (forest[i][j], (i, j)))

        start = (0, 0)
        result = 0
        while min_heap:
            tree = heapq.heappop(min_heap)
            step = minStep(forest, start, tree, m, n)
            if step < 0:
                return -1
            result += step
            start = tree[1]
        return result
