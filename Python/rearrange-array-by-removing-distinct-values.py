# Time:  O(nlogn)
# Space: O(n)

import collections


# freq table, sort
class Solution(object):
    def rearrangeArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        result = []
        vals = sorted(cnt.iterkeys())
        while vals:
            new_vals = []
            for x in vals:
                result.append(x)
                cnt[x] -= 1
                if cnt[x]:
                    new_vals.append(x)
            vals = new_vals
        return result
