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

# Reference: https://discuss.leetcode.com/topic/103532/my-python-solution-inspired-by-a-algorithm/2
class Solution(object):
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        def minStep(p1, p2):
            min_steps = abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
            stack1, stack2 = [p1], []
            used, visited = {p1}, {p1}

            while True:
                if not stack1:
                    # cannot find a path in stack1 from p1 to p2,
                    # try other possible paths in stack2 with extra 2 steps
                    stack1, stack2 = stack2, stack1
                    used.update(stack1)
                    min_steps += 2

                if not stack1:  # no any other possible path
                    return -1

                (i, j) = stack1.pop()
                if (i, j) == p2:
                    break

                add1, add2 = [], []
                if i == p2[0]:
                    add2.append((i-1, j))
                    add2.append((i+1, j))
                elif i < p2[0]:
                    add2.append((i-1, j))
                    add1.append((i+1, j))
                else:
                    add1.append((i-1, j))
                    add2.append((i+1, j))

                if j == p2[1]:
                    add2.append((i, j-1))
                    add2.append((i, j+1))
                elif j < p2[1]:
                    add2.append((i, j-1))
                    add1.append((i, j+1))
                else:
                    add1.append((i, j-1))
                    add2.append((i, j+1))

                for (ii, jj) in add1:
                    if 0 <= ii < m and 0 <= jj < n and forest[ii][jj] and (ii, jj) not in used:
                        visited.add((ii, jj))
                        stack1.append((ii, jj))
                        used.add((ii, jj))
                for (ii, jj) in add2:
                    if 0 <= ii < m and 0 <= jj < n and forest[ii][jj] and (ii, jj) not in visited:
                        visited.add((ii, jj))
                        stack2.append((ii, jj))

            return min_steps

        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
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
            used = {p1}
            q = collections.deque([p1])
            while q:
                size = len(q)
                for _ in xrange(size):
                    (i, j) = q.popleft()
                    if (i, j) == p2:
                        return min_steps
                    for direction in directions:
                        ii, jj = i+direction[0], j+direction[1]
                        if not (0 <= ii < m and 0 <= jj < n and forest[ii][jj] and (ii, jj) not in used):
                            continue
                        q.append((ii, jj))
                        used.add((ii, jj))
                min_steps += 1
            return -1
        
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]
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
