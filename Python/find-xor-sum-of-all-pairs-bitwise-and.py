# Time:  O(n)
# Space: O(1)

import operator


class Solution(object):
    def getXORSum(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        return reduce(operator.xor, arr1) & reduce(operator.xor, arr2)
