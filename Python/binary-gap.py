# Time:  O(logn) = O(1) due to n is a 32-bit number
# Space: O(1)

class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        result = 0
        last = None
        for i in xrange(32):
            if (N >> i) & 1:
                if last is not None:
                    result = max(result, i-last)
                last = i
        return result

