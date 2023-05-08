# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minIncrements(self, n, cost):
        """
        :type n: int
        :type cost: List[int]
        :rtype: int
        """
        result = 0
        while n != 1:
            result += abs(cost[n-2]-cost[n-1])
            cost[(n-2)//2] += max(cost[n-2], cost[n-1])
            n -= 2
        return result
