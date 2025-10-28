# Time:  O(n)
# Space: O(n)

import collections


# prefix sum, freq table
class Solution(object):
    def numGoodSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = prefix = 0
        cnt = collections.defaultdict(int)
        cnt[0] = 1
        i = 0
        while i < len(nums):
            j, prefix2 = i, prefix
            while j < len(nums) and nums[j] == nums[i]:
                prefix2 = (prefix2+nums[j])%k
                result += cnt[prefix2]
                j += 1
            while i < j:
                prefix = (prefix+nums[i])%k
                cnt[prefix] += 1
                i += 1
        return result


# Time:  O(n)
# Space: O(n)
import collections


# prefix sum, freq table
class Solution2(object):
    def numGoodSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result = prefix = 0
        cnt = collections.defaultdict(int)
        cnt[0] = 1
        for x in nums:
            prefix = (prefix+x)%k
            result += cnt[prefix]
            cnt[prefix] += 1
        l = 0
        for i in xrange(len(nums)):
            l += 1
            if i+1 == len(nums) or nums[i+1] != nums[i]:
                for j in xrange(1, l+1):
                    if nums[i]*j%k == 0:
                        result -= (l-j+1)-1
                l = 0
        return result
