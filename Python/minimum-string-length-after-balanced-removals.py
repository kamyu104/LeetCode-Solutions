# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def minLengthAfterRemovals(self, s):
        """
        :type s: str
        :rtype: int
        """
        return abs(s.count('a')-s.count('b'))
