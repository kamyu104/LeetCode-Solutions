# Time:  O(n)
# Space: O(k)

import collections


class Solution(object):
    def constrainedSubsetSum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result, dq = float("-inf"), collections.deque()
        for i in xrange(len(nums)):
            if dq and i-dq[0][0] == k+1:
                dq.popleft()
            curr = nums[i] + (dq[0][1] if dq else 0)
            while dq and dq[-1][1] <= curr:
                dq.pop()
            if curr > 0:
                dq.append((i, curr))
            result = max(result, curr)
        return result
