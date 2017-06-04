# Time:  O(n)
# Space: O(1)

# A zero-indexed array A consisting of N different integers is given.
# The array contains all integers in the range [0, N - 1].
#
# Sets S[K] for 0 <= K < N are defined as follows:
#
# S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
#
# Sets S[K] are finite for each K and should NOT contain duplicates.
#
# Write a function that given an array A consisting of N integers,
# return the size of the largest set S[K] for this array.
#
# Example 1:
# Input: A = [5,4,0,3,1,6,2]
# Output: 4
# Explanation: 
# A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
#
# One of the longest S[K]:
# S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
# Note:
# N is an integer within the range [1, 20,000].
# The elements of A are all distinct.
# Each element of array A is an integer within the range [0, N-1].

class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for num in nums:
            if num != None:
                start, count = num, 0
                while nums[start] != None:
                    temp = start
                    start = nums[start]
                    nums[temp] = None
                    count += 1
                result = max(result, count)
        return result
 
