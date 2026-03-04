# Time:  O(n)
# Space: O(n)

import collections


# freq table, two pointers
class Solution(object):
    def countSubarrays(self, nums, k, m):
        """
        :type nums: List[int]
        :type k: int
        :type m: int
        :rtype: int
        """
        cnt1, cnt2 = collections.defaultdict(int), collections.defaultdict(int)
        result = left = right = l = 0
        for x in nums:
            cnt1[x] += 1
            while len(cnt1) == k+1:
                cnt1[nums[left]] -= 1
                if cnt1[nums[left]] == 0:
                    del cnt1[nums[left]]
                left += 1
            cnt2[x] += 1
            if cnt2[x] == m:
                l += 1
            while l == k:
                if cnt2[nums[right]] == m:
                    l -= 1
                cnt2[nums[right]] -= 1
                if cnt2[nums[right]] == 0:
                    del cnt2[nums[right]]
                right += 1
            result += max(right-left, 0)
        return result
