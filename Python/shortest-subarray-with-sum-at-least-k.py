# Time:  O(n)
# Space: O(n)

# Return the length of the shortest, non-empty,
# contiguous subarray of A with sum at least K.
# If there is no non-empty subarray with sum at least K, return -1.
#
# Example 1:
#
# Input: A = [1], K = 1
# Output: 1
# Example 2:
#
# Input: A = [1,2], K = 4
# Output: -1
# Example 3:
#
# Input: A = [2,-1,2], K = 3
# Output: 3
#
# Note:
# - 1 <= A.length <= 50000
# - -10 ^ 5 <= A[i] <= 10 ^ 5
# - 1 <= K <= 10 ^ 9

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

import collections


class Solution(object):
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        accumulated_sum = [0]*(len(A)+1)
        for i in xrange(len(A)):
            accumulated_sum[i+1] = accumulated_sum[i]+A[i]

        result = float("inf")
        mono_increasing_q = collections.deque()
        for i, curr in enumerate(accumulated_sum):
            while mono_increasing_q and curr <= \
                    accumulated_sum[mono_increasing_q[-1]]:
                mono_increasing_q.pop()
            while mono_increasing_q and \
                    curr-accumulated_sum[mono_increasing_q[0]] >= K:
                result = min(result, i-mono_increasing_q.popleft())
            mono_increasing_q.append(i)
        return result if result != float("inf") else -1
