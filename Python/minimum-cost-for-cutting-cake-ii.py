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

