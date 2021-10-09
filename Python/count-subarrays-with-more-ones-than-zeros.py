# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def subarraysWithMoreZerosThanOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7

        lookup = collections.defaultdict(int)
        lookup[0] = 1
        result = total = same = more = 0
        for x in nums:
            total += 1 if x == 1 else -1
            new_same = lookup[total]
            new_more = (same+more+1)%MOD if x == 1 else (more-new_same)%MOD
            lookup[total] += 1
            result = (result+new_more)%MOD
            same, more = new_same, new_more
        return result


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def subarraysWithMoreZerosThanOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7

        lookup = {0:-1}
        dp = [0]*len(nums)
        result = total = 0
        for i, x in enumerate(nums):
            total += 1 if x == 1 else -1
            if total not in lookup:
                if total > 0:
                    dp[i] = i+1
            else:
                j = lookup[total]
                if j != -1:
                    dp[i] = dp[j]
                if x > 0:
                    dp[i] += (i-1)-j
            lookup[total] = i
            result = (result+dp[i])%MOD
        return result
