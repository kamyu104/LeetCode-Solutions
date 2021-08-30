# Time:  O(n)
# Space: O(n)

import itertools


class Solution(object):
    def widestPairOfIndices(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        lookup = {0:-1}
        result = total = 0
        for i, (n1, n2) in enumerate(itertools.izip(nums1, nums2)):
            total += n1-n2
            if total not in lookup:
                lookup[total] = i
            result = max(result, i-lookup[total])
        return result
