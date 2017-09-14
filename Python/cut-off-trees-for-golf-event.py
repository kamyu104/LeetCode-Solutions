# Time:  O(t * (logt + m * n)), t is the number of trees
# Space: O(t + m * n)

# You are asked to cut off trees in a forest for a golf event.
# The forest is represented as a non-negative 2D map, in this map:
#
# 0 represents the obstacle can't be reached.
# 1 represents the ground can be walked through.
# The place with number bigger than 1 represents a tree can be walked through,
# and this positive number represents the tree's height.
#
# You are asked to cut off all the trees in this forest in the order of tree's height -
# always cut off the tree with lowest height first. And after cutting, the original place
# has the tree will become a grass (value 1).
#
# You will start from the point (0, 0)
# and you should output the minimum steps you need to walk to cut off all the trees.
# If you can't cut off all the trees, output -1 in that situation.
#
# You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.
#
# Example 1:
# Input: 
# [
#  [1,2,3],
#  [0,0,4],
#  [7,6,5]
# ]
# Output: 6
# Example 2:
# Input: 
# [
#  [1,2,3],
#  [0,0,0],
#  [7,6,5]
# ]
# Output: -1
# Example 3:
# Input: 
# [
#  [2,3,4],
#  [0,0,5],
#  [8,7,6]
# ]
# Output: 6
# Explanation: You started from the point (0,0) and you can cut off the tree
# in (0,0) directly without walking.
# Hint: size of the given matrix will not exceed 50x50.

# Solution Reference: 
# 1. https://discuss.leetcode.com/topic/103532/my-python-solution-inspired-by-a-algorithm/2
# 2. https://discuss.leetcode.com/topic/103562/python-solution-based-on-wufangjie-s-hadlock-s-algorithm
# 3. https://en.wikipedia.org/wiki/A*_search_algorithm
class Solution(object):
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        def minStep(p1, p2):
            min_steps = abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
            curr, soon = [p1], []
            lookup = set()
            while True:
                if not curr:
                    # cannot find a path in current stack from p1 to p2,
                    # try other possible paths in sooner stack with extra 2 steps
                    curr, soon = soon, curr
                    min_steps += 2
                if not curr:  # no any other possible path
                    return -1
                i, j = curr.pop()
                if (i, j) == p2:
                    return min_steps
                if (i, j) not in lookup:
                    lookup.add((i, j))
                    for i, j, closer in (i+1, j, i < p2[0]), (i-1, j, i > p2[0]), (i, j+1, j < p2[1]), (i, j-1, j > p2[1]):
                        if 0 <= i < m and 0 <= j < n and forest[i][j] and (i, j) not in lookup:
                            (curr if closer else soon).append((i, j))

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
