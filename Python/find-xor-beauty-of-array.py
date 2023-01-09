# Time:  O(n)
# Space: O(1)

import operator


# bit manipulation, math
class Solution(object):
    def xorBeauty(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(operator.xor, nums)
