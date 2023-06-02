# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def removeTrailingZeros(self, num):
        """
        :type num: str
        :rtype: str
        """
        return num[:next(i for i in reversed(xrange(len(num))) if num[i] != '0')+1]
