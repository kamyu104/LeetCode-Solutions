# Time:  O(n)
# Space: O(n)

import itertools


# Ascending stack solution
class Solution(object):
    def sumSubarrayMins(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        M = 10**9 + 7

        left, s1 = [0]*len(A), []
        for i in xrange(len(A)):
            count = 1
            while s1 and s1[-1][0] > A[i]:
                count += s1.pop()[1]
            left[i] = count
            s1.append([A[i], count])

        right, s2 = [0]*len(A), []
        for i in reversed(xrange(len(A))):
            count = 1
            while s2 and s2[-1][0] >= A[i]:
                count += s2.pop()[1]
            right[i] = count
            s2.append([A[i], count])

        return sum(a*l*r for a, l, r in itertools.izip(A, left, right)) % M

