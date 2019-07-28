# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def largestUniqueNumber(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.append(-1)
        return max(k for k,v in collections.Counter(A).items() if v == 1)
