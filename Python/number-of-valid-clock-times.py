# Time:  O(1)
# Space: O(1)

# combinatorics
class Solution(object):
    def countTime(self, time):
        """
        :type time: str
        :rtype: int
        """
        result = 1
        if time[4] == '?':
            result *= 10
        if time[3] == '?':
            result *= 6
        if time[1] == time[0] == '?':
            result *= 24
        elif time[1] == '?':
            result *= 10 if time[0] != '2' else 4
        elif time[0] == '?':
            result *= 3 if time[1] < '4' else 2
        return result
