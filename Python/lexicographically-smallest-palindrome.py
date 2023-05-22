# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def makeSmallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        return "".join(min(s[i], s[~i]) for i in xrange(len(s)))
