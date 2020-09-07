# Time:  O(m * n)
# Space: O(m * n)

# topological sort solution
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        if not matrix:
            return 0
        
        in_degree = [[0]*len(matrix[0]) for _ in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                for di, dj in directions:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(matrix) and
                            0 <= nj < len(matrix[0]) and
                            matrix[ni][nj] > matrix[i][j]):
                        continue
                    in_degree[i][j] += 1
        q = []
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if not in_degree[i][j]:
                    q.append((i, j))
        result = 0
        while q:
            new_q = []
            for i, j in q:
                for di, dj in directions:
                    ni, nj = i+di, j+dj
                    if not (0 <= ni < len(matrix) and
                            0 <= nj < len(matrix[0]) and
                            matrix[i][j] > matrix[ni][nj]):
                        continue
                    in_degree[ni][nj] -= 1
                    if not in_degree[ni][nj]:
                        new_q.append((ni, nj))
            q = new_q
            result += 1         
        return result


# Time:  O(m * n)
# Space: O(m * n)
# dfs + memoization solution
class Solution2(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

        def longestpath(matrix, i, j, max_lengths):
            if max_lengths[i][j]:
                return max_lengths[i][j]
            max_depth = 0
            for di, dj in directions:
                x, y = i+di, j+dj
                if 0 <= x < len(matrix) and 0 <= y < len(matrix[0]) and \
                   matrix[x][y] < matrix[i][j]:
                    max_depth = max(max_depth, longestpath(matrix, x, y, max_lengths))
            max_lengths[i][j] = max_depth + 1
            return max_lengths[i][j]

        if not matrix:
            return 0
        result = 0
        max_lengths = [[0 for _ in xrange(len(matrix[0]))] for _ in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                result = max(result, longestpath(matrix, i, j, max_lengths))
        return result
