# Time:  O(n + 24)
# Space: O(24)

# freq table
class Solution(object):
    def countCompleteDayPairs(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        result = 0
        cnt = [0]*24
        for x in hours:
            result += cnt[-x%24]
            cnt[x%24] += 1
        return result
