# Time:  O(nlogn)
# Space: O(n)

from sortedcontainers import SortedList
import itertools


# sorted list, binary search
class Solution(object):
    def numberOfPairs(self, nums1, nums2, diff):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type diff: int
        :rtype: int
        """
        sl = SortedList()
        result = 0
        for x, y in itertools.izip(nums1, nums2):
            result += sl.bisect_right((x-y)+diff)
            sl.add(x-y)
        return result
