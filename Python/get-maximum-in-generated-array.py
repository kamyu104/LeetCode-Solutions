# Time:  O(n)
# Space: O(n)

nums = [0, 1]
dp = [0, 1]
class Solution(object):
    def getMaximumGenerated(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n+1 > len(dp):
            for i in xrange(len(nums), n+1):
                if i%2 == 0:
                    nums.append(nums[i//2])
                else:
                    nums.append(nums[i//2] + nums[i//2+1])
                dp.append(max(dp[-1], nums[-1]))
        return dp[n]


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def getMaximumGenerated(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        nums = [0]*(n+1)
        nums[1] = 1
        result = 1
        for i in xrange(2, n+1):
            if i%2 == 0:
                nums[i] = nums[i//2]
            else:
                nums[i] = nums[i//2] + nums[i//2+1]
            result = max(result, nums[i])
        return result
