# Time:  O(n * s * (logs + logr))
# Space: O(s)

# knapsack dp
class Solution(object):
    def minOperations(self, nums, sum):
        """
        :type nums: List[int]
        :type sum: int
        :rtype: int
        """
        INF = float("inf")
        dp = [INF]*(sum+1)
        dp[0] = 0
        for x in nums:
            for i in reversed(xrange(1, len(dp))):
                nx, c = x, 0
                while i-nx >= 0:
                    if dp[i-nx]+c < dp[i]:
                        dp[i] = dp[i-nx]+c
                    nx <<= 1
                    c += 1
                nx, c = x//2, 1
                while nx:
                    if i-nx >= 0:
                        if dp[i-nx]+c < dp[i]:
                            dp[i] = dp[i-nx]+c
                    nx >>= 1
                    c += 1
        return dp[sum] if dp[sum] is not INF else -1


# Time:  O(n * s * (logs + logr))
# Space: O(s + logs + logr)
# knapsack dp
class Solution2(object):
    def minOperations(self, nums, sum):
        """
        :type nums: List[int]
        :type sum: int
        :rtype: int
        """
        INF = float("inf")
        dp = [INF]*(sum+1)
        dp[0] = 0
        for x in nums:
            candidates = []
            nx, c = x, 0
            while sum-nx >= 0:
                candidates.append((nx, c))
                nx <<= 1
                c += 1
            nx, c = x//2, 1
            while nx:
                if sum-nx >= 0:
                    candidates.append((nx, c))
                nx >>= 1
                c += 1
            new_dp = dp[:]
            for nx, c in candidates:
                for i in xrange(nx, len(dp)):
                    if dp[i-nx]+c < new_dp[i]:
                        new_dp[i] = dp[i-nx]+c
            dp = new_dp
        return dp[sum] if dp[sum] is not INF else -1
