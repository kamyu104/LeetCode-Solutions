# Time:  O(n)
# Space: o(n)

import collections


# freq table, two pointers, sliding window
class Solution(object):
    def maxSubarrayLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = collections.Counter()
        result = left = 0
        for right in xrange(len(nums)):
            cnt[nums[right]] += 1
            while not (cnt[nums[right]] <= k):
                cnt[nums[left]] -= 1
                left += 1
            result = max(result, right-left+1)
        return result
