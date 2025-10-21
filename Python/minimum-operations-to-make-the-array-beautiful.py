# Time:  O(n * rlogr), r = max(nums)
# Space: O(r)

# dp
class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        INF = float("inf")
        mx = max(nums)
        if mx == 1:
            return 0
        dp = [INF]*((2*mx-2)+1)
        dp[nums[0]] = 0
        for i in xrange(1, len(nums)):
            new_dp = [INF]*len(dp)
            for x in xrange(1, len(dp)):
                if dp[x] == INF:
                    continue
                for j in xrange(ceil_divide(nums[i], x), (len(dp)-1)//x+1):
                    new_dp[j*x] = min(new_dp[j*x], dp[x]+(j*x-nums[i]))
            dp = new_dp
        return min(dp)
