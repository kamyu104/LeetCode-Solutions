# Time:  O(n)
# Space: O(1)

# In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL",
# a move consists of either replacing one occurrence of "XL" with "LX",
# or replacing one occurrence of "RX" with "XR".
# Given the starting string start and the ending string end,
# return True if and only if there exists a sequence of moves to transform one string to the other.
#
# Example:
# Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
# Output: True
#
# Explanation:
# We can transform start to end following these steps:
# RXXLRXRXL ->
# XRXLRXRXL ->
# XRLXRXRXL ->
# XRLXXRRXL ->
# XRLXXRRLX
#
# Note:
# - 1 <= len(start) = len(end) <= 10000.
# - Both start and end will only consist of characters in {'L', 'R', 'X'}.

class Solution(object):
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        N = len(start)
        i, j = 0, 0
        while i < N and j < N:
            while i < N and start[i] == 'X':
                i += 1
            while j < N and end[j] == 'X':
                j += 1
            if (i < N) != (j < N):
                return False
            elif i < N and j < N:
                if start[i] != end[j] or \
                   (start[i] == 'L' and i < j) or \
                   (start[i] == 'R' and i > j):
                    return False
            i += 1
            j += 1
        return True
