# Time:  O(n)
# Space: O(1)

class Solution(object):
    def modifyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        for i in xrange(len(s)):
            if s[i] != '?':
                continue
            for c in ('a', 'b', 'c'):
                if (i == 0 or s[i-1] != c) and (i == len(s)-1 or c != s[i+1]):
                    break
            s[i] = c
        return "".join(s)
