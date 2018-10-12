# Time:  O(t * (logt + m * n)), t is the number of trees
# Space: O(t + m * n)

import collections
import heapq


class Solution(object):
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        def dot(p1, p2):
            return p1[0]*p2[0]+p1[1]*p2[1]

        def minStep(p1, p2):
            min_steps = abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
            closer, detour = [p1], []
            lookup = set()
            while True:
                if not closer:  # cannot find a path in the closer expansions
                    if not detour:  # no other possible path
                        return -1
                    # try other possible paths in detour expansions with extra 2-step cost
                    min_steps += 2
                    closer, detour = detour, closer
                i, j = closer.pop()
                if (i, j) == p2:
                    return min_steps
                if (i, j) not in lookup:
                    lookup.add((i, j))
                    for I, J in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                        if 0 <= I < m and 0 <= J < n and forest[I][J] and (I, J) not in lookup:
                            is_closer = dot((I-i, J-j), (p2[0]-i, p2[1]-j)) > 0
                            (closer if is_closer else detour).append((I, J))
            return min_steps

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
            step = minStep(start, tree[1])
            if step < 0:
                return -1
            result += step
            start = tree[1]
        return result


# Time:  O(t * (logt + m * n)), t is the number of trees
# Space: O(t + m * n)
class Solution_TLE(object):
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        def minStep(p1, p2):
            min_steps = 0
            lookup = {p1}
            q = collections.deque([p1])
            while q:
                size = len(q)
                for _ in xrange(size):
                    (i, j) = q.popleft()
                    if (i, j) == p2:
                        return min_steps
                    for i, j in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
                        if not (0 <= i < m and 0 <= j < n and forest[i][j] and (i, j) not in lookup):
                            continue
                        q.append((i, j))
                        lookup.add((i, j))
                min_steps += 1
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
            step = minStep(start, tree[1])
            if step < 0:
                return -1
            result += step
            start = tree[1]
        return result

