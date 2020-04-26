# Time:  O(n)
# Space: O(k)

from collections import deque


class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        result, dq = [], deque()
        for i in xrange(len(nums)):
            if dq and i-dq[0] == k:
                dq.popleft()
            while dq and nums[dq[-1]] <= nums[i]:
                dq.pop()
            dq.append(i)
            if i >= k-1:
                result.append(nums[dq[0]])
        return result
