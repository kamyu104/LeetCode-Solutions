# Time:  O(1)
# Space: O(1)

# Given a time represented in the format "HH:MM",
# form the next closest time by reusing the current digits.
# There is no limit on how many times a digit can be reused.
#
# You may assume the given input string is always valid.
# For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
#
# Example 1:
#
# Input: "19:34"
# Output: "19:39"
# Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
# It is not 19:33, because this occurs 23 hours and 59 minutes later.
#
# Example 2:
#
# Input: "23:59"
# Output: "22:22"
# Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
# It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        h, m = time.split(":")
        curr = int(h) * 60 + int(m)
        result = None
        for i in xrange(curr+1, curr+1441):
            t = i % 1440
            h, m = t // 60, t % 60
            result = "%02d:%02d" % (h, m)
            if set(result) <= set(time):
                break
        return result
