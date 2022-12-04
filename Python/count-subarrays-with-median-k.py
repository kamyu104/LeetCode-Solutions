# Time:  O(n)
# Space: O(n)

import collections


# freq table, prefix sum
class Solution(object):
    def countSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        idx = nums.index(k)
        lookup = collections.Counter()
        curr = 0
        for i in reversed(xrange(idx+1)):
            curr += 0 if nums[i] == k else -1 if nums[i] < k else +1
            lookup[curr] += 1
        result = curr = 0
        for i in xrange(idx, len(nums)):
            curr += 0 if nums[i] == k else -1 if nums[i] < k else +1
            result += lookup[-curr]+lookup[-(curr-1)]
        return result
