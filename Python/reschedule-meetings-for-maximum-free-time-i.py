# Time:  O(n)
# Space: O(1)

# two pointers, sliding window
class Solution(object):
    def maxFreeTime(self, eventTime, k, startTime, endTime):
        """
        :type eventTime: int
        :type k: int
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        startTime.append(eventTime)
        endTime.insert(0, 0)
        result = curr = 0
        for i in xrange(len(startTime)):
            curr += startTime[i]-endTime[i]
            result = max(result, curr)
            if i-k >= 0:
                curr -= startTime[i-k]-endTime[i-k]
        return result
