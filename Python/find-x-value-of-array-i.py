# Time:  O(n * k)
# Space: O(k)

# dp
class Solution(object):
    def resultArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        result = [0]*k
        dp = [0]*k
        for x in nums:
            new_dp = [0]*k
            new_dp[x%k] += 1
            for i, c in enumerate(dp):
                new_dp[i*x%k] += c
            for i, c in enumerate(new_dp):
                result[i] += c 
            dp = new_dp
        return result
