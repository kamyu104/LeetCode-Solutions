# Time:  O(n)
# Space: O(1)

# array
class Solution(object):
    def earliestTime(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: int
        """
        return min(s+t for s, t in tasks)
