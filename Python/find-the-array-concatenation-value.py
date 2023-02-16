# Time:  O(nlogr)
# Space: O(1)

import math


# math
class Solution(object):
    def findTheArrayConcVal(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum((nums[i]*10**(int(math.log10(nums[~i]))+1) for i in xrange(len(nums)//2)))+sum(nums[i] for i in xrange(len(nums)//2, len(nums)))
