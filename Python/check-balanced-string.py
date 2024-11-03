# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def isBalanced(self, num):
        """
        :type num: str
        :rtype: bool
        """
        return sum(ord(num[i])-ord('0') for i in xrange(0, len(num), 2)) == sum(ord(num[i])-ord('0') for i in xrange(1, len(num), 2))
