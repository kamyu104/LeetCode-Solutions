# Time:  O(h)
# Space: O(h)

import itertools


# line sweep
class Solution(object):
    def maxArea(self, height, positions, directions):
        """
        :type height: int
        :type positions: List[int]
        :type directions: str
        :rtype: int
        """
        events = [0]*(2*height+1)
        for d, i in itertools.izip(directions, positions):
            if d == 'U':
                events[height-i] -= 1
                events[(height-i)+height] += 1
            else:
                events[i] += 1
                events[i+height] -= 1
        result = total = sum(positions)
        cnt = directions.count('U')
        for t in xrange(1, len(events)):
            total += -(len(directions)-cnt)+cnt
            result = max(result, total)
            cnt += events[t]
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections
import itertools


# sort, line sweep
class Solution2(object):
    def maxArea(self, height, positions, directions):
        """
        :type height: int
        :type positions: List[int]
        :type directions: str
        :rtype: int
        """
        events = collections.defaultdict(int)
        for d, i in itertools.izip(directions, positions):
            if d == 'U':
                events[height-i] -= 1
                events[(height-i)+height] += 1
            else:
                events[i] += 1
                events[i+height] -= 1
        result = total = sum(positions)
        cnt = directions.count('U')
        prev = 0
        for t, diff in sorted(events.iteritems()):
            total += (t-prev)*(-(len(directions)-cnt)+cnt)
            result = max(result, total)
            cnt += diff
            prev = t
        return result
