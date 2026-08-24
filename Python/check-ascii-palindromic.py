# Time:  O(n)
# Space: O(1)

# string, bitmasks
class Solution(object):
    def isPalindromic(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def reverse(x):
            result = 0
            for _ in xrange(8):
                result = (result<<1)|(x&1)
                x >>= 1
            return result
            
        def check(x, y):
            return ord(x) == reverse(ord(y))

        return all(check(s[i], s[~i]) for i in xrange((len(s)+1)//2))
