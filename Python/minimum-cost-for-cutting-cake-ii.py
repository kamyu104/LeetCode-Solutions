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

