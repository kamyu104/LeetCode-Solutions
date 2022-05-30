# Time:  O(n * l)
# Space: O(n)

import collections
import itertools


# freq table
class Solution(object):
    def largestWordCount(self, messages, senders):
        """
        :type messages: List[str]
        :type senders: List[str]
        :rtype: str
        """
        cnt = collections.Counter()
        for m, s in itertools.izip(messages, senders):
            cnt[s] += m.count(' ')+1
        return max((k for k in cnt.iterkeys()), key=lambda x: (cnt[x], x))
