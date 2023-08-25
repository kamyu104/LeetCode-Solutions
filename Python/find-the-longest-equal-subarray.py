# Time:  O(n)
# Space: O(n)

import collections


# freq table, two pointers, sliding window
class Solution(object):
    def longestEqualSubarray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = collections.Counter()
        result = left = 0
        for right in xrange(len(nums)):
            cnt[nums[right]] += 1
            result = max(result, cnt[nums[right]])
            if right-left+1 > result+k:
                cnt[nums[left]] -= 1
                left += 1
        return result
