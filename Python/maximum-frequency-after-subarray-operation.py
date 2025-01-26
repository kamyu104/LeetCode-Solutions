# Time:  O(n)
# Space: O(n)

import collections


# freq table, dp
class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = 0
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] = max(cnt[x], cnt[k])+1
            result = max(result+int(x == k), cnt[x])
        return result
