# Time:  O(n)
# Space: O(n)

import collections


# two pointers, sliding window
class Solution(object):
    def countGood(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = curr = left = 0
        cnt = collections.Counter()
        for right in xrange(len(nums)):
            curr += cnt[nums[right]]
            cnt[nums[right]] += 1
            while curr >= k:
                cnt[nums[left]] -= 1
                curr -= cnt[nums[left]]
                left += 1
            result += left
        return result
