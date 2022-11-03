# Time:  O(n)
# Space: O(s), s is the value of space

import collections


# freq table
class Solution(object):
    def destroyTargets(self, nums, space):
        """
        :type nums: List[int]
        :type space: int
        :rtype: int
        """
        cnt = collections.Counter(x%space for x in nums)
        mx = max(cnt.itervalues())
        return min(x for x in nums if cnt[x%space] == mx)
