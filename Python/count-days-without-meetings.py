# Time:  O(nlogn)
# Space: O(1)

# sort
class Solution(object):
    def countDays(self, days, meetings):
        """
        :type days: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        meetings.sort()
        result = curr = 0
        for s, e in meetings:
            result += max((s-1)-curr, 0)
            curr = max(curr, e)
        result += days-curr
        return result
