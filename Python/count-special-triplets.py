# Time:  O(n)
# Space: O(n)

import collections


# dp
class Solution(object):
    def specialTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        dp = [collections.defaultdict(int) for _ in xrange(2)]
        for x in nums:
            if x%2 == 0 and x//2 in dp[1]:
                result = (result+dp[1][x//2])%MOD
            if 2*x in dp[0]:
                dp[1][x] = (dp[1][x]+dp[0][2*x])%MOD
            dp[0][x] = (dp[0][x]+1)%MOD
        return result


# Time:  O(n)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def specialTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        result = 0
        right = collections.defaultdict(int)
        for x in nums:
            right[x] += 1
        left = collections.defaultdict(int)
        for x in nums:
            right[x] -= 1
            if not right[x]:
                del right[x]
            if 2*x in left and 2*x in right:
                result = (result+left[2*x]*right[2*x])%MOD
            left[x] += 1
        return result
