# Time:  O(n * l)
# Space: O(1)

import itertools


class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        result = 0
        for col in itertools.izip(*A):
            if any(col[i] > col[i+1] for i in xrange(len(col)-1)):
                result += 1
        return result
