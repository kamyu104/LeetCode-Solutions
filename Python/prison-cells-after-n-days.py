# Time:  O(1)
# Space: O(1)

class Solution(object):
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        N -= max(N-1, 0) // 14 * 14  # 14 is got from Solution2
        for i in xrange(N):
            cells = [0] + [cells[i-1] ^ cells[i+1] ^ 1 for i in xrange(1, 7)] + [0]
        return cells


# Time:  O(1)
# Space: O(1)
class Solution2(object):
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        cells = tuple(cells)
        lookup = {}
        while N:
            lookup[cells] = N
            N -= 1
            cells = tuple([0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in xrange(1, 7)] + [0])
            if cells in lookup:
                assert(lookup[cells] - N in (1, 7, 14))
                N %= lookup[cells] - N
                break

        while N:
            N -= 1
            cells = tuple([0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in xrange(1, 7)] + [0])
        return list(cells)
