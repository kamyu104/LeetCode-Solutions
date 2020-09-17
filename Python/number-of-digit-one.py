
# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        digit, result = 1, 0
        base = 1
        while n >= base:
            result += (n//(10*base))*base + \
                      min(base, max(n%(10*base) - digit*base + 1, 0))
            base *= 10
        return result

