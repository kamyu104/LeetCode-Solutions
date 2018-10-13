# Time:  O(n)
# Space: O(n)

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

