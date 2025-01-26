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
        result = cnt_k = 0
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] = max(cnt[x], cnt_k)+1
            if x == k:
                cnt_k += 1
                result += 1
            result = max(result, cnt[x])
        return result
