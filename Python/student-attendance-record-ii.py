# Time:  O(n)
# Space: O(1)

# Given a positive integer n, return the number of all possible attendance records with length n,
# which will be regarded as rewardable. The answer may be very large, return it after mod 10^9 + 7.
#
# A student attendance record is a string that only contains the following three characters:
#
# 'A' : Absent.
# 'L' : Late.
# 'P' : Present.
# A record is regarded as rewardable if it doesn't
# contain more than one 'A' (absent) or more than two continuous 'L' (late).
#
# Example 1:
# Input: n = 2
# Output: 8 
# Explanation:
# There are 8 records with length 2 will be regarded as rewardable:
# "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
# Only "AA" won't be regarded as rewardable owing to more than one absent times. 
# Note: The value of n won't exceed 100,000.

class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        M = 1000000007
        a0l0, a0l1, a0l2, a1l0, a1l1, a1l2 = 1, 0, 0, 0, 0, 0
        for i in xrange(n+1):
            a0l2, a0l1, a0l0 = a0l1, a0l0, (a0l0 + a0l1 + a0l2) % M
            a1l2, a1l1, a1l0 = a1l1, a1l0, (a0l0 + a1l0 + a1l1 + a1l2) % M;
        return a1l0
