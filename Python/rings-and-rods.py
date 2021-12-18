# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def countPoints(self, rings):
        """
        :type rings: str
        :rtype: int
        """
        bits = {'R':0b001, 'G':0b010, 'B':0b100}
        rods = collections.defaultdict(int)
        for i in xrange(0, len(rings), 2):
            rods[int(rings[i+1])] |= bits[rings[i]]
        return sum(x == 0b111 for x in rods.itervalues())
