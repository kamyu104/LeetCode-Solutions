# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def checkAlmostEquivalent(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        k = 3
        cnt1, cnt2 = collections.Counter(word1), collections.Counter(word2)
        return all(abs(cnt1[c]-cnt2[c]) <= k for c in set(cnt1.keys()+cnt2.keys()))

