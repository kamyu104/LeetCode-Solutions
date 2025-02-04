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
        result = curr = 0
        for i in xrange(len(startTime)+1):
            curr += (startTime[i] if i != len(startTime) else eventTime)-(endTime[i-1] if i-1 >= 0 else 0)
            result = max(result, curr)
            if i-k >= 0:
                curr -= startTime[i-k]-(endTime[i-k-1] if i-k-1 >= 0 else 0)
        return result
