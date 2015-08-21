# Time:  O(n)
# Space: O(n)

class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return sum(v % 2 for k, v in collections.Counter(s).iteritems()) <  2
