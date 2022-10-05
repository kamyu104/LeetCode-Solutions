# Time:  O(n)
# Space: O(1)

import operator


# bit manipulation
class Solution(object):
    def xorAllNums(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        return (reduce(operator.xor, nums1) if len(nums2)%2 else 0) ^ \
               (reduce(operator.xor, nums2) if len(nums1)%2 else 0)
