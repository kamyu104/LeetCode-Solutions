# Time:  O(n)
# Space: O(n)

import collections


# mono deque, two pointers
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        max_dq = collections.deque()
        min_dq = collections.deque()
        left = 0
        for right in xrange(len(nums)):
            while max_dq and nums[max_dq[-1]] <= nums[right]:
                max_dq.pop()
            max_dq.append(right)
            while min_dq and nums[min_dq[-1]] >= nums[right]:
                min_dq.pop()
            min_dq.append(right)
            while (right-left+1)*(nums[max_dq[0]]-nums[min_dq[0]]) > k:
                if max_dq and max_dq[0] == left:
                    max_dq.popleft()
                if min_dq and min_dq[0] == left:
                    min_dq.popleft()
                left += 1
            result += right-left+1
        return result
