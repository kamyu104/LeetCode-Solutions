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
