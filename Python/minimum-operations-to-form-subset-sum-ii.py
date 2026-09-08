# Time:  O(n * s * logr * logs)
# Space: O(s + logr * logs)

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
            lookup = [INF]*(sum+1)
            nx1, c1 = x, 0
            while nx1:
                nx2, c2 = nx1, c1
                while nx2 <= sum:
                    if c2 < lookup[nx2]:
                        lookup[nx2] = c2
                    c2 += 1
                    nx2 <<= 1
                c1 += 1
                nx1 >>= 1
            new_dp = dp[:]
            for nx, c in enumerate(lookup):
                if c is INF:
                    continue
                for i in xrange(nx, len(dp)):
                    if dp[i-nx] is INF:
                        continue
                    if dp[i-nx]+c < new_dp[i]:
                        new_dp[i] = dp[i-nx]+c
            dp = new_dp
        return dp[sum] if dp[sum] is not INF else -1


# Time:  O(n * s * logr * logs)
# Space: O(s + logr * logs)
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
            lookup = [INF]*(sum+1)
            nx1, c1 = x, 0
            while nx1:
                nx2, c2 = nx1, c1
                while nx2 <= sum:
                    if c2 < lookup[nx2]:
                        lookup[nx2] = c2
                    c2 += 1
                    nx2 <<= 1
                c1 += 1
                nx1 >>= 1
            candidates = [(nx, c) for nx, c in enumerate(lookup) if c is not INF]
            for i in reversed(xrange(1, len(dp))):
                for nx, c in candidates:
                    if not (i-nx >= 0 and dp[i-nx] is not INF):
                        continue
                    if dp[i-nx]+c < dp[i]:
                        dp[i] = dp[i-nx]+c
        return dp[sum] if dp[sum] is not INF else -1


# Time:  O(n * s * logr * logs)
# Space: O(s)
# knapsack dp
class Solution3(object):
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
            nx1, c1 = x, 0
            new_dp = dp[:]
            while nx1:
                nx2, c2 = nx1, c1
                while nx2 <= sum:
                    for i in xrange(nx2, len(dp)):
                        if i-nx2 >= 0 and dp[i-nx2] is not INF:
                            if dp[i-nx2]+c2 < new_dp[i]:
                                new_dp[i] = dp[i-nx2]+c2
                    c2 += 1
                    nx2 <<= 1
                c1 += 1
                nx1 >>= 1
            dp = new_dp
        return dp[sum] if dp[sum] is not INF else -1
