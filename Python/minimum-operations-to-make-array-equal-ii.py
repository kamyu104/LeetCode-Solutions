# Time:  O(n)
# Space: O(1)

import itertools


# greedy
class Solution(object):
    def minOperations(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        cnt1 = cnt2 = 0
        for x, y in itertools.izip(nums1, nums2):
            if y == x:
                continue
            if k == 0 or (y-x)%k:
                return -1
            if x < y:
                cnt1 += (y-x)//k
            else:
                cnt2 += (x-y)//k
        return cnt1 if cnt1 == cnt2 else -1
