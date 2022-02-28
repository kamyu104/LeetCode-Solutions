# Time:  O(n)
# Space: O(1)

import collections


# freq table
class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        cnt1, cnt2 = collections.Counter(s), collections.Counter(t)
        return sum((cnt1-cnt2).itervalues())+sum((cnt2-cnt1).itervalues())
