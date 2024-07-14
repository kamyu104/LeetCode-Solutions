# Time:  O(mlogm + nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        """
        :type m: int
        :type n: int
        :type horizontalCut: List[int]
        :type verticalCut: List[int]
        :rtype: int
        """
        horizontalCut.sort()
        verticalCut.sort()
        result = 0
        cnt_h = cnt_v = 1
        while horizontalCut or verticalCut:
            if not verticalCut or (horizontalCut and horizontalCut[-1] > verticalCut[-1]):
                result += horizontalCut.pop()*cnt_h
                cnt_v += 1
            else:
                result += verticalCut.pop()*cnt_v
                cnt_h += 1
        return result


# Time:  O(mlogm + nlogn)
# Space: O(1)
# sort, greedy
class Solution2(object):
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        """
        :type m: int
        :type n: int
        :type horizontalCut: List[int]
        :type verticalCut: List[int]
        :rtype: int
        """
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)
        result = i = j = 0
        while i < len(horizontalCut) or j < len(verticalCut):
            if j == len(verticalCut) or (i < len(horizontalCut) and horizontalCut[i] > verticalCut[j]):
                result += horizontalCut[i]*(j+1)
                i += 1
            else:
                result += verticalCut[j]*(i+1)
                j += 1
        return result


# Time:  O((m + n) * m^2 * n^2)
# Space: O(m^2 * n^2)
# memoization
class Solution3(object):
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        """
        :type m: int
        :type n: int
        :type horizontalCut: List[int]
        :type verticalCut: List[int]
        :rtype: int
        """
        def memoization(x1, y1, x2, y2):
            if (x1, y1) == (x2, y2):
                return 0
            if lookup[x1][y1][x2][y2] == -1:
                mn = float("inf")
                for x in xrange(x1, x2):
                    mn = min(ret, memoization(x1, y1, x, y2)+memoization(x+1, y1, x2, y2)+horizontalCut[x])
                for y in xrange(y1, y2):
                    mn = min(ret, memoization(x1, y1, x2, y)+memoization(x1, y+1, x2, y2)+verticalCut[y])
                lookup[x1][y1][x2][y2] = mn
            return lookup[x1][y1][x2][y2]

        lookup = [[[[-1]*n for _ in range(m)]for _ in range(n)] for _ in range(m)]
        return memoization(0, 0, m-1, n-1)

