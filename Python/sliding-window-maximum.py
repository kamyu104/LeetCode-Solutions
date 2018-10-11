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
        dq = deque()
        max_numbers = []

        for i in xrange(len(nums)):
            while dq and nums[i] >= nums[dq[-1]]:
                dq.pop()
            dq.append(i)
            if i >= k and dq and dq[0] == i - k:
                dq.popleft()
            if i >= k - 1:
                max_numbers.append(nums[dq[0]])

        return max_numbers

