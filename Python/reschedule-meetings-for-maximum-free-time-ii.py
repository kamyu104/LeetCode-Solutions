# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def maxFreeTime(self, eventTime, startTime, endTime):
        """
        :type eventTime: int
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        def topk(a, k):  # Time: O(k * n)
            result = [[float("-inf")]*2 for _ in xrange(k)]
            for x in a:
                for i in xrange(len(result)):
                    if x > result[i]:
                        result[i], x = x, result[i]
            return result

        result = 0
        startTime.append(eventTime)
        endTime.insert(0, 0)
        diffs = ([startTime[i]-endTime[i], endTime[i]] for i in xrange(len(startTime)))
        top3 = topk(diffs, 3)
        for i in xrange(len(startTime)-1):
            for mx, e in top3:
                if e not in (endTime[i], endTime[i+1]) and endTime[i+1]-startTime[i] <= mx:
                    result = max(result, (startTime[i]-endTime[i])+(startTime[i+1]-endTime[i+1])+(endTime[i+1]-startTime[i]))
                    break
            else:
                result = max(result, (startTime[i]-endTime[i])+(startTime[i+1]-endTime[i+1]))
        return result
