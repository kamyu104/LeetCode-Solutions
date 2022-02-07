# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def minimumTime(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        result = left+(len(s)-0)
        for i in xrange(1, len(s)+1):
            left = min(left+2*(s[i-1] == '1'), i)
            result = min(result, left+(len(s)-i))
        return result


# Time:  O(n)
# Space: O(n)
# dp
class Solution2(object):
    def minimumTime(self, s):
        """
        :type s: str
        :rtype: int
        """
        result, right = len(s), [0]*(len(s)+1)
        for i in reversed(xrange(len(s))):
            right[i] = min(right[i+1]+2*(s[i] == '1'), len(s)-i)
        left = 0
        result = left+right[0]
        for i in xrange(1, len(s)+1):
            left = min(left+2*(s[i-1] == '1'), i)     
            result = min(result, left+right[i])
        return result
