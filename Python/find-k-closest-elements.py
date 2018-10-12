# Time:  O(logn + k)
# Space: O(1)

import bisect


class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        i = bisect.bisect_left(arr, x)
        left, right = i-1, i
        while k:
            if right >= len(arr) or \
               (left >= 0 and abs(arr[left]-x) <= abs(arr[right]-x)):
                left -= 1
            else:
                right += 1
            k -= 1
        return arr[left+1:right]

