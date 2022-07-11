# Time:  O(nlogn + nlogr), r is max((abs(i-j) for i, j in itertools.izip(nums1, nums2))
# Space: O(n)

import itertools


# binary search
class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k1: int
        :type k2: int
        :rtype: int
        """
        def check(diffs, k, x):
            return sum(max(d-x, 0) for d in diffs) <= k

        diffs = sorted((abs(i-j) for i, j in itertools.izip(nums1, nums2)), reverse=True)
        k = min(k1+k2, sum(diffs))
        left, right = 0, diffs[0]
        while left <= right:
            mid = left + (right-left)//2
            if check(diffs, k, mid):
                right = mid-1
            else:
                left = mid+1
        k -= sum(max(d-left, 0) for d in diffs)
        for i in xrange(len(diffs)):
            diffs[i] = min(diffs[i], left)-int(i < k)
        return sum(d**2 for d in diffs)
