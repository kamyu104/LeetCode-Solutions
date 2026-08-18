# Time:  O(n + m)
# Space: O(1)

# greedy
class Solution(object):
    def minPenalty(self, period, lights, arrivalTime):
        """
        :type period: int
        :type lights: List[int]
        :type arrivalTime: List[int]
        :rtype: int
        """
        mx = max(lights)
        result = 0
        for x in arrivalTime:
            x %= period
            if x < mx:
                continue
            result = max(result, period-x)
        return result
