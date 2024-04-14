# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def scoreOfString(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(abs(ord(s[i+1])-ord(s[i])) for i in xrange(len(s)-1))
