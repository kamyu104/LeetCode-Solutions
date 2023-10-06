# Time:  O(n)
# Space: O(n)

import collections


# freq table, greedy
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        cnt = collections.Counter(nums)
        return sum(ceil_divide(x, 3) for x in cnt.itervalues()) if all(x >= 2 for x in cnt.itervalues()) else -1
