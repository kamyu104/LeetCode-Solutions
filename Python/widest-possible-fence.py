# Time:  O(n + c^2), c = len(cnt)
# Space: O(c^2)

import collections


# freq table
class Solution(object):
    def maximumWidth(self, planks):
        """
        :type planks: List[int]
        :rtype: int
        """
        cnt1 = collections.defaultdict(int)
        for x in planks:
            cnt1[x] += 1
        cnt2 = collections.defaultdict(int, cnt1)
        cnt = cnt1.items()
        for i in xrange(len(cnt)):
            x, c1 = cnt[i]
            cnt2[x+x] += c1//2
            for j in xrange(i):
                y, c2 = cnt[j]
                cnt2[x+y] += min(c1, c2)
        return max(cnt2.itervalues())
