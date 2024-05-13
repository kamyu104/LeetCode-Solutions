# Time:  O((n-1)^2 * 2^(n-1))
# Space: O((n-1) * 2^(n-1))

# dp, backtracing
class Solution(object):
    def findPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        n = len(nums)
        dp = [[(INF, -1) for _ in xrange(n-1)] for _ in xrange(1<<(n-1))]
        for i in xrange(n-1):
            dp[1<<i][i] = (abs((i+1)-nums[0]), -1)
        for mask in xrange(1<<(n-1)):
            for i in xrange(n-1):
                if mask&(1<<i) == 0:
                    continue
                for j in xrange(n-1):
                    if j == i or mask&(1<<j) == 0:
                        continue
                    dp[mask][i] = min(dp[mask][i], (dp[mask^(1<<i)][j][0]+abs((i+1)-nums[j+1]), j))
        _, i = min((dp[-1][i][0]+abs(0-nums[i+1]), i) for i in xrange(n-1))
        result = [0]
        mask = (1<<(n-1))-1
        while i != -1:
            result.append(i+1)
            mask, i = mask^(1<<i), dp[mask][i][1]
        return result
