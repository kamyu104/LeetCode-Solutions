# Time:  O(n^4)
# Space: O(n^3)

# In a given integer array A, we must move every element of A to
# either list B or list C. (B and C initially start empty.)
#
# Return true if and only if after such a move, it is possible that
# the average value of B is equal to the average value of C, and B and C are both non-empty.
#
# Example :
# Input: 
# [1,2,3,4,5,6,7,8]
# Output: true
# Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
#
# Note:
# - The length of A will be in the range [1, 30].
# - A[i] will be in the range of [0, 10000].

class Solution(object):
    def splitArraySameAverage(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        def possible(total, n):
            for i in xrange(1, n//2+1):
                if total*i%n == 0:
                    return True
            return False
        n, s = len(A), sum(A)
        if not possible(n, s):
            return False

        sums = [set() for _ in xrange(n//2+1)];
        sums[0].add(0)
        for num in A:  # O(n) times
            for i in reversed(xrange(1, n//2+1)):  # O(n) times
                for prev in sums[i-1]:  # O(1) + O(2) + ... O(n/2) = O(n^2) times
                    sums[i].add(prev+num)
        for i in xrange(1, n//2+1):
            if s*i%n == 0 and s*i//n in sums[i]:
                return True
        return False
