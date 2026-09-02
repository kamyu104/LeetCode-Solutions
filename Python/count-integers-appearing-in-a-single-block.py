# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def countSpecialIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        cnt = collections.defaultdict(int)
        for i in xrange(len(nums)):
            if not (i+1 == len(nums) or nums[i+1] != nums[i]):
                continue
            if cnt[nums[i]] == 0:
                result += 1
            elif cnt[nums[i]] == 1:
                result -= 1
            cnt[nums[i]] += 1
        return result
