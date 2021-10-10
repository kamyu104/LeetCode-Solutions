# Time:  O(n * 2^n)
# Space: O(2^n)

import itertools
import bisect


class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = nums[:len(nums)//2], nums[len(nums)//2:]
        total1, total2 = sum(left), sum(right)
        result = float("inf")
        for k in xrange(len(left)+1): 
            sums = sorted(2*sum(comb)-total1 for comb in itertools.combinations(left, k))
            for comb in itertools.combinations(right, len(left)-k): 
                diff = 2*sum(comb)-total2
                i = bisect.bisect_left(sums, -diff)
                if i < len(sums):
                    result = min(result, abs(sums[i]+diff))
                if i > 0:
                    result = min(result, abs(sums[i-1]+diff))
        return result
