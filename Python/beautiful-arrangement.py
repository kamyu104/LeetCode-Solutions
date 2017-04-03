# Time:  O(n!)
# Space: O(n)

# Suppose you have N integers from 1 to N.
# We define a beautiful arrangement as an array that is constructed by these N numbers successfully 
# if one of the following is true for the ith position (1 <= i <= N) in this array:
#
# The number at the ith position is divisible by i.
# i is divisible by the number at the ith position.
# Now given N, how many beautiful arrangements can you construct?
#
# Example 1:
# Input: 2
# Output: 2
# Explanation: 
#
# The first beautiful arrangement is [1, 2]:
#
# Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
#
# Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
#
# The second beautiful arrangement is [2, 1]:
#
# Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
#
# Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
# Note:
# N is a positive integer and will not exceed 15.

class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def countArrangementHelper(n, arrangement):
            if n <= 0:
                return 1
            count = 0
            for i in xrange(n):
                if arrangement[i] % n == 0 or n % arrangement[i] == 0:
                    arrangement[i], arrangement[n-1] = arrangement[n-1], arrangement[i]
                    count += countArrangementHelper(n - 1, arrangement)
                    arrangement[i], arrangement[n-1] = arrangement[n-1], arrangement[i]
            return count

        return countArrangementHelper(N, range(1, N+1))
