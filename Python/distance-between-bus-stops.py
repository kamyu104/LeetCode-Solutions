# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def distanceBetweenBusStops(self, distance, start, destination):
        """
        :type distance: List[int]
        :type start: int
        :type destination: int
        :rtype: int
        """
        if start > destination:
            start, destination = destination, start
        s_to_d = sum(itertools.islice(distance, start, destination))
        d_to_s = sum(itertools.islice(distance, 0, start)) + \
                 sum(itertools.islice(distance, destination, len(distance)))
        return min(s_to_d, d_to_s)
