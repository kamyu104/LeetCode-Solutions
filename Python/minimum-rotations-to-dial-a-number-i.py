# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def minRotations(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i in xrange(len(s)):
            diff = abs(ord(s[i])-ord(s[i-1] if i-1 >= 0 else '0'))
            result += min(diff, 10-diff)
        return result
