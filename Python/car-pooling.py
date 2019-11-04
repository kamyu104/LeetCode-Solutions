# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        line = [x for num, start, end in trips for x in [[start, num], [end, -num]]]
        line.sort()
        for _, num in line:
            capacity -= num
            if capacity < 0:
                return False
        return True
