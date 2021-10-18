# Time:  O(nlogn)
# Space: O(1)

import itertools


class Solution(object):
    def minMovesToSeat(self, seats, students):
        """
        :type seats: List[int]
        :type students: List[int]
        :rtype: int
        """
        seats.sort()
        students.sort()
        return sum(abs(a-b) for a, b in itertools.izip(seats, students))
