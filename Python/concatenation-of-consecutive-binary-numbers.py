# Time:  O(n)
# Space: O(1)

class Solution(object):
    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9+7
        result = l = 0
        for i in xrange(1, n+1):
            if i&(i-1) == 0:
                l += 1
            result = ((result<<l)%MOD+i)%MOD
        return result
