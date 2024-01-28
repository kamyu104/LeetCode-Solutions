# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def countKeyChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(s[i].lower() != s[i+1].lower() for i in xrange(len(s)-1))
