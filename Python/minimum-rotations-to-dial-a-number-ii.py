# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def minRotations(self, n, s):
        """
        :type n: int
        :type s: str
        :rtype: int
        """
        def f(a, b):
            diff = abs(ord(a)-ord(b))
            return min(diff, 10-diff)

        result = mx = 0
        for i in xrange(len(s)):
            result += f(s[i], s[i-1] if i-1 >= 0 else '0')
            mx = max(mx, f(s[i], s[i-1] if i-1 >= 0 else '0')-f(s[-1], s[i-1] if i-1 >= 0 else '0'))
        return result-mx
