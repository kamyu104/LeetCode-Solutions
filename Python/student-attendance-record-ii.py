# Time:  O(n)
# Space: O(1)

class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        M = 1000000007
        a0l0, a0l1, a0l2, a1l0, a1l1, a1l2 = 1, 0, 0, 0, 0, 0
        for i in xrange(n+1):
            a0l2, a0l1, a0l0 = a0l1, a0l0, (a0l0 + a0l1 + a0l2) % M
            a1l2, a1l1, a1l0 = a1l1, a1l0, (a0l0 + a1l0 + a1l1 + a1l2) % M
        return a1l0

