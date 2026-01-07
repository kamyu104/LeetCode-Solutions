# Time:  O(n)
# Space: O(n)

import collections


# freq table, two pointers
class Solution(object):
    def minLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        cnt = collections.defaultdict(int)
        result = INF
        left = curr = 0
        for right in xrange(len(nums)):
            cnt[nums[right]] += 1
            if cnt[nums[right]] == 1:
                curr += nums[right]
            while curr >= k:
                result = min(result, right-left+1)
                if cnt[nums[left]] == 1:
                    curr -= nums[left]
                cnt[nums[left]] -= 1
                left += 1
        return result if result is not INF else -1
