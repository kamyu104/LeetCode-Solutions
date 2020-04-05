# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        count = collections.Counter(s)
        odd = sum(v%2 for v in count.itervalues())
        return odd <= k <= len(s)
