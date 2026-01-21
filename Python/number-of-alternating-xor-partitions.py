# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def alternatingXOR(self, nums, target1, target2):
        """
        :type nums: List[int]
        :type target1: int
        :type target2: int
        :rtype: int
        """
        MOD = 10**9+7
        vals = [0, target1, target1^target2, target2]
        dp = [0]*len(vals)
        dp[0] = 1
        prefix = 0
        for i in xrange(len(nums)-1):
            new_dp = dp[:]
            prefix ^= nums[i]            
            for j in xrange(len(vals)):
                if vals[j] != prefix:
                    continue
                new_dp[j] = (new_dp[j]+dp[(j-1)%len(dp)])%MOD
            dp = new_dp
        prefix ^= nums[-1]
        result = 0
        for i in xrange(len(vals)):
            if vals[i] != prefix:
                continue
            result = (result+dp[(i-1)%len(dp)])%MOD
        return result


# Time:  O(n)
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def alternatingXOR(self, nums, target1, target2):
        """
        :type nums: List[int]
        :type target1: int
        :type target2: int
        :rtype: int
        """
        MOD = 10**9+7
        cnt1 = collections.defaultdict(int)
        cnt2 = collections.defaultdict(int)
        cnt2[0] = 1
        result = prefix = 0
        for x in nums:
            prefix ^= x
            c1 = cnt2[prefix^target1]
            c2 = cnt1[prefix^target2]
            cnt1[prefix] = (cnt1[prefix]+c1)%MOD
            cnt2[prefix] = (cnt2[prefix]+c2)%MOD
        return (c1+c2)%MOD
