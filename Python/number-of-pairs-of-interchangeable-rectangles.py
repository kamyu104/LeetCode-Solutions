# Time:  O(n)
# Space: O(n)

import collections
import fractions


class Solution(object):
    def interchangeableRectangles(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        count = collections.defaultdict(int)
        for w, h in rectangles:
            g = fractions.gcd(w, h)  # Time: O(logx) ~= O(1)
            count[(w//g, h//g)] += 1
        return sum(c*(c-1)//2 for c in count.itervalues())
