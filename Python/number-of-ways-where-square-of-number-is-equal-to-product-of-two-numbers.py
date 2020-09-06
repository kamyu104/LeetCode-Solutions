# Time:  O(m * n)
# Space: O(m + n)

import collections


class Solution(object):
    def numTriplets(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def two_product(nums, i):
            count = 0
            lookup = collections.defaultdict(int)
            for num in nums:
                if i%num:
                    continue
                count += lookup[i//num]
                lookup[num] += 1
            return count
        
        result = 0
        for num in nums1:
            result += two_product(nums2, num**2)
        for num in nums2:
            result += two_product(nums1, num**2)
        return result
