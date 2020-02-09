# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        diff = collections.Counter(s) - collections.Counter(t)
        return sum(diff.itervalues())
