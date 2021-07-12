# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
        first, last = [len(s)]*26, [-1]*26
        for i, c in enumerate(s):
            first[ord(c)-ord('a')] = min(first[ord(c)-ord('a')], i)
            last[ord(c)-ord('a')] = max(last[ord(c)-ord('a')], i)
        return sum(len(set(s[i] for i in xrange(first[c]+1, last[c]))) for c in xrange(26))
