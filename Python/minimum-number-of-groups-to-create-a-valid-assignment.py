# Time:  O(min(cnt.values()) * n/min(cnt.values())) = O(n)
# Space: O(n)

import collections


# linear search, greedy, math
class Solution(object):
    def minGroupsForValidAssignment(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        INF = float("inf")

        def ceil_divide(a, b):
            return (a+b-1)//b
    
        def count(x):
            result = 0
            for c in cnt.itervalues():
                if c%x > c//x:
                    return INF
                result += ceil_divide(c, x+1)
            return result

        cnt = collections.Counter(nums)
        for i in reversed(xrange(1, min(cnt.itervalues())+1)):
            c = count(i)
            if c != INF:
                return c
        return 0
