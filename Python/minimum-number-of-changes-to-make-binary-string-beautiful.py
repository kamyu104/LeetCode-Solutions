# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minChanges(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(s[i] != s[i+1] for i in xrange(0, len(s), 2))
