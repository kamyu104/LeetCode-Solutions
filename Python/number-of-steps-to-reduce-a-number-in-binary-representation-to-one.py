# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, carry = 0, 0
        for i in reversed(xrange(1, len(s))):
            if int(s[i]) + carry == 1:
                carry = 1  # once it was set, it would keep carrying forever
                result += 2
            else:
                result += 1
        return result+carry
