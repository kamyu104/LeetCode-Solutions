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
        result = 0
        for c in capacity:
            cnt = min(c, additionalRocks)
            additionalRocks -= cnt
            c -= cnt
            if not c:
                result += 1
        return result
