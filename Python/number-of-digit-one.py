
# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        DIGIT = 1
        result = int(DIGIT == 0)
        base = 1
        while n >= base:
            result += (n//(10*base)-int(DIGIT == 0))*base + \
                      min(base, max(n%(10*base) - DIGIT*base + 1, 0))
            base *= 10
        return result

