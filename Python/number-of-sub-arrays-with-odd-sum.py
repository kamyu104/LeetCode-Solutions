# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numOfSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        result, accu = 0, 0
        dp = [1, 0]
        for x in arr:
            accu ^= x&1
            dp[accu] += 1
            result = (result + dp[accu^1]) % MOD
        return result
