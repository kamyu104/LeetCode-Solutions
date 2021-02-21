# Time:  O(26 * n) = O(n)
# Space: O(26 * n) = O(n)

class Solution(object):
    def longestNiceSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        lookup = set(list(s))
        prev = -1
        result = ""
        for i in xrange(len(s)+1):
            if not (i == len(s) or s[i] not in lookup or s[i].swapcase() not in lookup):
                continue
            if prev == -1 and i == len(s):
                return s
            tmp = self.longestNiceSubstring(s[prev+1:i])
            if len(tmp) > len(result):
                result = tmp
            prev = i
        return result
