# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList


# sorted list, binary search
class Solution(object):
    def minAbsoluteDifference(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        result = float("inf")
        sl = SortedList()
        for i in xrange(x, len(nums)):
            sl.add(nums[i-x])
            j = sl.bisect_left(nums[i])
            if j-1 >= 0:
                result = min(result, nums[i]-sl[j-1])
            if j < len(sl):
                result = min(result, sl[j]-nums[i])
        return result
