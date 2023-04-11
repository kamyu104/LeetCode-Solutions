# Time:  O(n)
# Space: O(n)

import collections


# freq table, prefix sum
class Solution(object):
    def distance(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [0]*len(nums)
        cnt1, left = collections.Counter(), collections.Counter()
        for i in xrange(len(nums)):
            result[i] += cnt1[nums[i]]*i-left[nums[i]]
            cnt1[nums[i]] += 1
            left[nums[i]] += i
        cnt2, right = collections.Counter(), collections.Counter()
        for i in reversed(xrange(len(nums))):
            result[i] += right[nums[i]]-cnt2[nums[i]]*i
            cnt2[nums[i]] += 1
            right[nums[i]] += i
        return result
