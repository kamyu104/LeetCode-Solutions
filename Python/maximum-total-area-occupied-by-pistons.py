# Time:  O(h)
# Space: O(h)

import itertools


# line sweep, difference array
class Solution(object):
    def maxArea(self, height, positions, directions):
        """
        :type height: int
        :type positions: List[int]
        :type directions: str
        :rtype: int
        """
        diff = [0]*(2*height+1)
        for d, i in itertools.izip(directions, positions):
            if d == 'U':
                diff[height-i] -= 1
                diff[(height-i)+height] += 1
            else:
                diff[i] += 1
                diff[i+height] -= 1
        result = total = sum(positions)
        cnt = directions.count('U')
        for t in xrange(1, len(diff)):
            total += -(len(directions)-cnt)+cnt
            result = max(result, total)
            cnt += diff[t]
        return result


# Time:  O(nlogn)
# Space: O(n)
import collections
import itertools


# sort, line sweep, difference array
class Solution2(object):
    def maxArea(self, height, positions, directions):
        """
        :type height: int
        :type positions: List[int]
        :type directions: str
        :rtype: int
        """
        diff = collections.defaultdict(int)
        for d, i in itertools.izip(directions, positions):
            if d == 'U':
                diff[height-i] -= 1
                diff[(height-i)+height] += 1
            else:
                diff[i] += 1
                diff[i+height] -= 1
        result = total = sum(positions)
        cnt = directions.count('U')
        prev = 0
        for t, d in sorted(diff.iteritems()):
            total += (t-prev)*(-(len(directions)-cnt)+cnt)
            result = max(result, total)
            cnt += d
            prev = t
        return result
