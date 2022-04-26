# Time:  O(nlogn + mlogn)
# Space: O(n)

import bisect


# line sweep, binary search
class Solution(object):
    def fullBloomFlowers(self, flowers, persons):
        """
        :type flowers: List[List[int]]
        :type persons: List[int]
        :rtype: List[int]
        """
        cnt = collections.Counter()
        for s, e in flowers:
            cnt[s] += 1
            cnt[e+1] -= 1
        events = sorted(cnt.iterkeys())
        prefix = [0]
        for x in events:
            prefix.append(prefix[-1]+cnt[x])
        return [prefix[bisect.bisect_right(events, t)] for t in persons]


# Time:  O(nlogn + mlogn)
# Space: O(n)
import bisect


# binary search
class Solution(object):
    def fullBloomFlowers(self, flowers, persons):
        """
        :type flowers: List[List[int]]
        :type persons: List[int]
        :rtype: List[int]
        """
        starts, ends = [], []
        for s, e in flowers:
            starts.append(s)
            ends.append(e+1)
        starts.sort()
        ends.sort()
        return [bisect.bisect_right(starts, t)-bisect.bisect_right(ends, t) for t in persons]
