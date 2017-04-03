# Time:  O(nlogn)
# Space: O(n)

# Given a list of 24-hour clock time points in "Hour:Minutes" format,
# find the minimum minutes difference between any two time points in the list.
#
# Example 1:
# Input: ["23:59","00:00"]
# Output: 1
# Note:
# The number of time points in the given list is at least 2 and won't exceed 20000.
# The input time is legal and ranges from 00:00 to 23:59.

class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        minutes = map(lambda x: int(x[:2]) * 60 + int(x[3:]), timePoints)
        minutes.sort()
        return min((y - x) % (24 * 60)  \
                   for x, y in zip(minutes, minutes[1:] + minutes[:1]))
