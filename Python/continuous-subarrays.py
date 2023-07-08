# Time:  O(n)
# Space: O(n)

import collections


# mono deque, two pointers
class Solution(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn, mx = collections.deque(), collections.deque()
        result = left = 0
        for right in xrange(len(nums)):
            while mn and nums[mn[-1]] > nums[right]:
                mn.pop()
            mn.append(right)
            while mx and nums[mx[-1]] < nums[right]:
                mx.pop()
            mx.append(right)
            while not nums[mx[0]]-nums[mn[0]] <= 2:
                if mn[0] < mx[0]:
                    mn.popleft()
                else:
                    mx.popleft()
                left = max(left, min(mn[0], mx[0]))
            result += right-left+1
        return result
