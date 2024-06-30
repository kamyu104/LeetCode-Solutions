# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        k = 2
        result = 0
        for i in xrange(k):
            dp = [0]*k
            for x in nums:
                dp[x%k] = dp[(i-x)%k]+1
            result = max(result, max(dp))
        return result


# Time:  O(n)
# Space: O(1)
# brute force
class Solution2(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return max(sum(x%2 == 0 for x in nums),
                   sum(x%2 == 1 for x in nums),
                   sum(nums[i]%2 != nums[i+1]%2 for i in xrange(len(nums)-1))+1)
