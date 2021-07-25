# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def areOccurrencesEqual(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return len(set(cnt for cnt in collections.Counter(s).itervalues())) == 1
