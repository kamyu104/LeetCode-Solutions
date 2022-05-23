# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maximumBags(self, capacity, rocks, additionalRocks):
        """
        :type capacity: List[int]
        :type rocks: List[int]
        :type additionalRocks: int
        :rtype: int
        """
        for i in xrange(len(capacity)):
            capacity[i] -= rocks[i]
        capacity.sort()
        for i, c in enumerate(capacity):
            if c > additionalRocks:
                return i
            additionalRocks -= c
        return len(capacity)
