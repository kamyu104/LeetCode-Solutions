# Time:  O(n)
# Space: O(n)

import collections


# math, freq table
class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums)%k:
            return False
        group_cnt = len(nums)//k 
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1 
        return all(x <= group_cnt for x in cnt.itervalues())
