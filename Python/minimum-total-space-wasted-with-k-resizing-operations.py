# Time:  O(k * n^2)
# Space: O(k * n)

class Solution(object):
    def minSpaceWastedKResizing(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        INF = float("inf")
        k += 1
        dp = [[INF]*(k+1) for _ in xrange(len(nums)+1)]
        dp[0][0] = 0
        for i in xrange(1, len(nums)+1):
            total = max_num = 0
            for j in reversed(xrange(1, i+1)):
                total += nums[j-1]
                max_num = max(max_num, nums[j-1])
                for m in xrange(1, k+1):
                    if dp[j-1][m-1] != INF:
                        dp[i][m] = min(dp[i][m], dp[j-1][m-1] + (max_num*(i-j+1)-total))
        return dp[-1][-1]
