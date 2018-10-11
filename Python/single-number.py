from __future__ import print_function
# Time:  O(n)
# Space: O(1)

import operator
from functools import reduce

class Solution:
    """
    :type nums: List[int]
    :rtype: int
    """
    def singleNumber(self, A):
        return reduce(operator.xor, A)

if __name__ == '__main__':
    print(Solution().singleNumber([1, 1, 2, 2, 3]))

