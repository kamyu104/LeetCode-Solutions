# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def minProcessingTime(self, processorTime, tasks):
        """
        :type processorTime: List[int]
        :type tasks: List[int]
        :rtype: int
        """
        K = 4
        processorTime.sort()
        tasks.sort(reverse=True)
        result = 0
        for i in xrange(len(processorTime)):
            for j in xrange(K):
                result = max(result, processorTime[i]+tasks[i*K+j])
        return result
