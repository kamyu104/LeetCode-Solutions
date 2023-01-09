# Time:  O(logn)
# Space: O(1)

import bisect


# binary search
class Solution(object):
    def maximumCount(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(bisect.bisect_left(nums, 0)-0, len(nums)-bisect.bisect_left(nums, 1))
