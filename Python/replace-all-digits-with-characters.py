# Time:  O(n)
# Space: O(1)

class Solution(object):
    def replaceDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        return "".join(chr(ord(s[i-1])+int(s[i])) if i%2 else s[i] for i in xrange(len(s)))
