# Time:  O(n)
# Space: O(n)

import collections


# freq table, two pointers, sliding window
class Solution(object):
    def maxSum(self, nums, m, k):
        """
        :type nums: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        lookup = collections.Counter()
        result = curr = left = 0
        for right in xrange(len(nums)):
            curr += nums[right]
            lookup[nums[right]] += 1
            if right-left+1 == k+1:
                lookup[nums[left]] -= 1
                if lookup[nums[left]] == 0:
                    del lookup[nums[left]]
                curr -= nums[left]
                left += 1
            if right-left+1 == k and len(lookup) >= m:
                result = max(result, curr)
        return result
