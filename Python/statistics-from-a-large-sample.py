# Time:  O(n)
# Space: O(1)

import bisect


class Solution(object):
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        n = sum(count)
        mi = next(i for i in xrange(len(count)) if count[i]) * 1.0
        ma = next(i for i in reversed(xrange(len(count))) if count[i]) * 1.0
        mean = sum(i * v for i, v in enumerate(count)) * 1.0 / n
        mode = count.index(max(count)) * 1.0
        for i in xrange(1, len(count)):
            count[i] += count[i-1]
        median1 = bisect.bisect_left(count, (n+1) // 2)
        median2 = bisect.bisect_left(count, (n+2) // 2)
        median = (median1+median2) / 2.0
        return [mi, ma, mean, median, mode]
