# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def countSuffix(self, nums, target):
        """
        :type nums: List[int]
        :type target: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        for x in target:
            cnt[x] -= 1
        if any(x for x in cnt.itervalues()):
            return 0
        right = 0
        while right+1 < len(nums) and nums[right] == target[right]:
            right += 1
        left = len(nums)-1
        while left-1 >= 0 and target[left-1] >= target[left]:
            left -= 1
        return max(right-left+1, 0)
