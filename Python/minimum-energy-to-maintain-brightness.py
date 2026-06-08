# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def minEnergy(self, n, brightness, intervals):
        """
        :type n: int
        :type brightness: int
        :type intervals: List[List[int]]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        intervals.sort(key=lambda x: x[0])
        result = 0
        left, right = 0, -1
        for l, r in intervals:
            if l <= right+1:
                right = max(right, r)
                continue
            result += right-left+1
            left, right = l, r
        result += right-left+1
        result *= ceil_divide(brightness, 3)
        return result
