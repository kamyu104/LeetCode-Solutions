# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counts = collections.Counter(nums)
        left, right = {}, {}
        for i, num in enumerate(nums):
            left.setdefault(num, i)
            right[num] = i
        degree = max(counts.values())
        return min(right[num]-left[num]+1 \
                   for num in counts.keys() \
                   if counts[num] == degree)

