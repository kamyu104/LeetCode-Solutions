# Time:  O(nlogn)
# Space: O(1)

# Given an array A of integers, for each integer A[i]
# we need to choose either x = -K or x = K, and add x to A[i] (only once).
#
# After this process, we have some array B.
#
# Return the smallest possible difference
# between the maximum value of B and the minimum value of B.
#
# Example 1:
#
# Input: A = [1], K = 0
# Output: 0
# Explanation: B = [1]
# Example 2:
#
# Input: A = [0,10], K = 2
# Output: 6
# Explanation: B = [2,8]
# Example 3:
#
# Input: A = [1,3,6], K = 3
# Output: 3
# Explanation: B = [4,6,3]
#
# Note:
# - 1 <= A.length <= 10000
# - 0 <= A[i] <= 10000
# - 0 <= K <= 10000

class Solution(object):
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        result = A[-1]-A[0]
        for i in xrange(len(A)-1):
            result = min(result,
                         max(A[-1]-K, A[i]+K) -
                         min(A[0]+K, A[i+1]-K))
        return result
