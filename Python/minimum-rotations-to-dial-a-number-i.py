# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def minRotations(self, s):
        """
        :type s: str
        :rtype: int
        """
        def f(a, b):
            diff = abs(ord(a)-ord(b))
            return min(diff, 10-diff)

        return sum(f(s[i], s[i-1] if i-1 >= 0 else '0') for i in xrange(len(s)))
