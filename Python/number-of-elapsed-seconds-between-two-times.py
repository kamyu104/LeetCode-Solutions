# Time:  O(1)
# Space: O(1)

# string
class Solution(object):
    def secondsBetweenTimes(self, startTime, endTime):
        """
        :type startTime: str
        :type endTime: str
        :rtype: int
        """
        def to_seconds(x):
            h, m, s = map(int, x.split(':'))
            return h*60*60+m*60+s
        
        return to_seconds(endTime)-to_seconds(startTime)
