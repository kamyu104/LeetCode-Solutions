# Time:  O(logr * nlogn)
# Space: O(n)

import bisect


# bitmasks, lis, binary search
class Solution(object):
    def longestSubsequence(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def lis(base):
            result = []
            for x in nums:
                if not x&base:
                    continue
                if not result or result[-1] < x:
                    result.append(x)
                else:
                    result[bisect.bisect_left(result, x)] = x
            return len(result)
    
        mx = max(nums)
        return max(lis(1<<l) for l in xrange(mx.bit_length())) if mx else 0
