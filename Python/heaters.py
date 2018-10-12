# Time:  O((m + n) * logn), m is the number of the houses, n is the number of the heaters.
# Space: O(1)

import bisect


class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters.sort()
        min_radius = 0
        for house in houses:
        	equal_or_larger = bisect.bisect_left(heaters, house)
        	curr_radius = float("inf")
        	if equal_or_larger != len(heaters):
        	    curr_radius = heaters[equal_or_larger] - house
        	if equal_or_larger != 0:
        	    smaller = equal_or_larger-1
        	    curr_radius = min(curr_radius, house - heaters[smaller])
        	min_radius = max(min_radius, curr_radius)
        return min_radius

