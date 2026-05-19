# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def isAdjacentDiffAtMostTwo(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return all(abs(ord(s[i])-ord(s[i+1])) <= 2 for i in xrange(len(s)-1))
