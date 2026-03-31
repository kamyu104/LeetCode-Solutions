# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def firstMatchingIndex(self, s):
        """
        :type s: str
        :rtype: int
        """
        return next((i for i in xrange(len(s)) if s[i] == s[~i]), -1)
