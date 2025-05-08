# Time:  O(4^n)
# Space: O(1)

# array
class Solution(object):
    def specialGrid(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def copy(l, r1, c1, r2, c2):
            for i in xrange(l):
                for j in xrange(l):
                    result[r2+i][c2+j] = result[r1+i][c1+j]+l*l
        
        total = 1<<n
        result = [[0]*total for _ in xrange(total)]
        l = 1
        for i in xrange(n):
            r, c = 0, total-l
            for dr, dc in ((l, 0), (0, -l), (-l, 0)):
                nr, nc = r+dr, c+dc
                copy(l, r, c, nr, nc)
                r, c = nr, nc
            l <<= 1
        return result


# Time:  O(4^n)
# Space: O(n)
# divide and conquer
class Solution2(object):
    def specialGrid(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def divide_and_conquer(l, r, c):
            if l == 1:
                result[r][c] = idx[0]
                idx[0] += 1
                return
            l >>= 1
            for dr, dc in ((0, l), (l, 0), (0, -l), (-l, 0)):
                r, c = r+dr, c+dc
                divide_and_conquer(l, r, c)

        total = 1<<n
        result = [[0]*total for _ in xrange(total)]
        idx = [0]
        divide_and_conquer(total, 0, 0)
        return result
