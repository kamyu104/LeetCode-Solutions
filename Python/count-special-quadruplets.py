# Time:  O(n^3)
# Space: O(n)

import collections


class Solution(object):
    def countQuadruplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        lookup = collections.defaultdict(int)
        lookup[nums[-1]] = 1
        for c in reversed(xrange(2, len(nums)-1)):
            for b in xrange(1, c):
                for a in xrange(b):
                    if nums[a]+nums[b]+nums[c] in lookup:
                        result += lookup[nums[a]+nums[b]+nums[c]]
            lookup[nums[c]] += 1
        return result
