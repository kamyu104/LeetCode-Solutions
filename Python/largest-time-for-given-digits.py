# Time:  O(1)
# Space: O(1)

import itertools


class Solution(object):
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        result = ""
        for i in xrange(len(A)):
            A[i] *= -1
        A.sort()
        for h1, h2, m1, m2 in itertools.permutations(A):
            hours = -(10*h1 + h2)
            mins = -(10*m1 + m2)
            if 0 <= hours < 24 and 0 <= mins < 60:
                result = "{:02}:{:02}".format(hours, mins)
                break
        return result
 
