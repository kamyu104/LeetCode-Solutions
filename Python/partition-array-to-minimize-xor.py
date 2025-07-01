# Time:  O(n^2 * k)
# Space: O(n)

# dp, prefix sum
class Solution(object):
    def minXor(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]^nums[i]
        dp = prefix[:]
        dp[0] = INF
        for l in xrange(2, k+1):
            for i in reversed(xrange(l-1, len(dp))):
                mn = INF
                for j in xrange(l-1, i):
                    v = prefix[i]^prefix[j]
                    mx = dp[j] if dp[j] > v else v
                    if mx < mn:
                        mn = mx
                dp[i] = mn
        return dp[-1]


# Time:  O(n^2 * k)
# Space: O(n)
# dp, prefix sum
class Solution2(object):
    def minXor(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]^nums[i]
        dp = [INF]*(len(nums)+1)
        dp[0] = 0
        for l in xrange(1, k+1):
            for i in reversed(xrange(l-1, len(dp))):
                dp[i] = INF
                for j in xrange(l-1, i):
                    dp[i] = min(dp[i], max(dp[j], prefix[i]^prefix[j]))
        return dp[-1]
