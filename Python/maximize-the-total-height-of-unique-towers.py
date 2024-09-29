# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maximumTotalSum(self, maximumHeight):
        """
        :type maximumHeight: List[int]
        :rtype: int
        """
        maximumHeight.sort()
        result, prev = 0, maximumHeight[-1]+1
        for x in reversed(maximumHeight):
            prev = min(x, prev-1)
            if prev == 0:
                return -1
            result += prev
        return result
