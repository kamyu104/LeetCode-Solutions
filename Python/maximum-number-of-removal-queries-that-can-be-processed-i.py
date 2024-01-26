# Time:  O(n^2)
# Space: O(n^2)

# dp
class Solution(object):
    def maximumProcessableQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: int
        """
        NEG_INF = float("-inf")
        dp = [[NEG_INF]*len(nums) for _ in xrange(len(nums))]
        dp[0][-1] = 0
        for l in reversed(xrange(1, len(nums))):
            for i in xrange(len(nums)-(l-1)):
                j = i+(l-1)
                left = dp[i-1][j] if i-1 >= 0 else NEG_INF
                right = dp[i][j+1] if j+1 < len(nums) else NEG_INF
                dp[i][j] = max(left, right)
                if i-1 >= 0 and nums[i-1] >= queries[left]:
                    dp[i][j] = max(dp[i][j], left+1)
                if j+1 < len(nums) and nums[j+1] >= queries[right]:
                    dp[i][j] = max(dp[i][j], right+1)
                if dp[i][j] == len(queries):
                    return len(queries)
        return max(dp[i][i]+int(nums[i] >= queries[dp[i][i]])for i in xrange(len(nums)))
