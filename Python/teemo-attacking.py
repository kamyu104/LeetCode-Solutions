# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        result = duration * len(timeSeries)
        for i in xrange(1, len(timeSeries)):
            result -= max(0, duration - (timeSeries[i] - timeSeries[i-1]))
        return result

