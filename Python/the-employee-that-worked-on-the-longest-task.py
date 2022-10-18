# Time:  O(l)
# Space: O(1)

# array
class Solution(object):
    def hardestWorker(self, n, logs):
        """
        :type n: int
        :type logs: List[List[int]]
        :rtype: int
        """
        return logs[max(xrange(len(logs)), key=lambda x: (logs[x][1]-(logs[x-1][1] if x-1 >= 0 else 0), -logs[x][0]))][0]
