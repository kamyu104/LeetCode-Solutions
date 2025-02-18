# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def hasSpecialSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        l = 0
        for i in xrange(len(s)):
            l += 1
            if i+1 == len(s) or s[i] != s[i+1]:
                if l == k:
                    return True
                l = 0
        return False
