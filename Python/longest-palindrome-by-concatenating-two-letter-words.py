# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        cnt = collections.Counter(words)
        result = remain = 0
        for x, c in cnt.iteritems():
            if x == x[::-1]:
                result += c//2
                remain |= c%2
            elif x < x[::-1] and x[::-1] in cnt:
                result += min(c, cnt[x[::-1]])
        return result*4+remain*2
