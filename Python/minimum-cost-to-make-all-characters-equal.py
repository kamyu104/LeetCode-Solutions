# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minimumCost(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(min(i+1, len(s)-(i+1)) for i in xrange(len(s)-1) if s[i] != s[i+1])
