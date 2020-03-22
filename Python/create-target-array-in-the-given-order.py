# Time:  O(n^2)
# Space: O(1)

import itertools


class Solution(object):
    def createTargetArray(self, nums, index):
        """
        :type nums: List[int]
        :type index: List[int]
        :rtype: List[int]
        """
        result = []
        for i, x in itertools.izip(index, nums):
            result.insert(i, x)
        return result
