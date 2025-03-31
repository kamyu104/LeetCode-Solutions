# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        return sum(i*(26-(ord(x)-ord('a'))) for i, x in enumerate(s, 1))
