# Time:  O(k * n)
# Space: O(n)

# prefix sum, dp
class Solution(object):
    def maxSum(self, nums, k, m):
        """
        :type nums: List[int]
        :type k: int
        :type m: int
        :rtype: int
        """
        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = prefix[i]+nums[i]
        dp = [float("-inf")]*(len(nums)+1)
        dp[0] = 0
        for i in xrange(1, k+1):
            new_dp = [float("-inf")]*(len(nums)+1)
            mx = float("-inf")
            for j in xrange(i*m-1, len(nums)):
                mx = max(mx, dp[(j+1)-m])
                new_dp[j+1] = (prefix[j+1]-prefix[(j+1)-m])+mx
                if j+1 != i*m:
                    new_dp[j+1] = max(new_dp[j+1], new_dp[j]+nums[j])
            dp = new_dp
        return max(dp)
