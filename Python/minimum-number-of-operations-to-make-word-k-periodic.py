# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def minimumOperationsToMakeKPeriodic(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        cnt = collections.Counter(word[i:i+k]for i in xrange(0, len(word), k))
        return len(word)//k-max(cnt.itervalues())
