# Time:  O(n * q)
# Space: O(n)

import itertools


class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: List[int]
        :type r: List[int]
        :rtype: List[bool]
        """
        def is_arith(n):
            mx, mn, lookup = max(n), min(n), set(n)
            if mx == mn:
                return True
            d, r = divmod(mx-mn, len(n)-1)
            if r:
                return False
            return all(i in lookup for i in xrange(mn, mx, d))
    
        result = []
        for left, right in itertools.izip(l, r):
            result.append(is_arith(nums[left:right+1]))
        return result
