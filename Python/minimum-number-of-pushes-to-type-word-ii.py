# Time:  O(n)
# Space: O(26)

import collections


# freq table, greedy
class Solution(object):
    def minimumPushes(self, word):
        """
        :type word: str
        :rtype: int
        """
        return sum(x*(i//(9-2+1)+1) for i, x in enumerate(sorted(collections.Counter(word).itervalues(), reverse=True)))
