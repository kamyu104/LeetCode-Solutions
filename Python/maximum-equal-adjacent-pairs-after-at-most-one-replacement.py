# Time:  O(n)
# Space: O(n)

import collections


# freq table
class Solution(object):
    def maxEqualAdjacentPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for i in xrange(len(nums)-1):
            if nums[i] != nums[i+1]:
                cnt[min(nums[i], nums[i+1]), max(nums[i], nums[i+1])] += 1
        return sum(nums[i] == nums[i+1] for i in xrange(len(nums)-1))+(max(cnt.itervalues()) if cnt else 0)
