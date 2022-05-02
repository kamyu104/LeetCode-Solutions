# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def removeDigit(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        i = next((i for i in xrange(len(number)-1) if digit == number[i] < number[i+1]), len(number)-1)
        if i+1 == len(number):
            i = next((i for i in reversed(xrange(len(number))) if digit == number[i]))
        return number[:i]+number[i+1:]
