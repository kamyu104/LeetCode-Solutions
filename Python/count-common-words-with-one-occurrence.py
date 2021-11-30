# Time:  O(m + n)
# Space: O(m + n)

import collections


class Solution(object):
    def countWords(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: int
        """
        cnt = collections.Counter(words1)
        for c in words2:
            if cnt[c] < 2:
                cnt[c] -= 1
        return sum(v == 0 for v in cnt.itervalues())
