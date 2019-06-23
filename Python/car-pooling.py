# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        lookup = collections.defaultdict(int)
        for num, start, end in trips:
            lookup[start] += num
            lookup[end] -= num
        intervals = [(location, num) for location, num in lookup.iteritems()]
        intervals.sort()
        for location, num in intervals:
            capacity -= num
            if capacity < 0:
                return False
        return True
