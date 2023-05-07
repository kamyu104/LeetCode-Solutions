# Time:  O(m * n)
# Space: O(1)

# backtracking, greedy, warnsdorff's rule
class Solution(object):
    def tourOfKnight(self, m, n, r, c):
        """
        :type m: int
        :type n: int
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        DIRECTIONS = ((1, 2), (-1, 2), (1, -2), (-1, -2),
                      (2, 1), (-2, 1), (2, -1), (-2, -1))
        def backtracking(r, c, i):
            def degree(x):
                cnt = 0
                r, c = x
                for dr, dc in DIRECTIONS:
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < m and 0 <= nc < n and result[nr][nc] == -1:
                        cnt += 1
                return cnt

            if i == m*n:
                return True
            candidates = []
            for dr, dc in DIRECTIONS:
                nr, nc = r+dr, c+dc
                if 0 <= nr < m and 0 <= nc < n and result[nr][nc] == -1:
                    candidates.append((nr, nc))
            for nr, nc in sorted(candidates, key=degree):  # warnsdorff's rule
                result[nr][nc] = i
                if backtracking(nr, nc, i+1):
                    return True
                result[nr][nc] = -1
            return False
    
        result = [[-1]*n for _ in xrange(m)]
        result[r][c] = 0
        backtracking(r, c, 1)
        return result


# Time:  O(8^(m * n - 1))
# Space: O(1)
# backtracking
class Solution2(object):
    def tourOfKnight(self, m, n, r, c):
        """
        :type m: int
        :type n: int
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        DIRECTIONS = ((1, 2), (-1, 2), (1, -2), (-1, -2),
                      (2, 1), (-2, 1), (2, -1), (-2, -1))
        def backtracking(r, c, i):
            if i == m*n:
                return True
            for dr, dc in DIRECTIONS:
                nr, nc = r+dr, c+dc
                if not (0 <= nr < m and 0 <= nc < n and result[nr][nc] == -1):
                    continue
                result[nr][nc] = i
                if backtracking(nr, nc, i+1):
                    return True
                result[nr][nc] = -1
            return False
    
        result = [[-1]*n for _ in xrange(m)]
        result[r][c] = 0
        backtracking(r, c, 1)
        return result
