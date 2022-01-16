# Time:  O(logn)
# Space: O(1)

# greedy
class Solution(object):
    def minMoves(self, target, maxDoubles):
        """
        :type target: int
        :type maxDoubles: int
        :rtype: int
        """
        result = 0
        while target > 1 and maxDoubles:
            result += 1+target%2
            target //= 2
            maxDoubles -= 1
        return result+(target-1)
