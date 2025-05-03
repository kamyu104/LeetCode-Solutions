# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, max_len = 0, 0
        dp = [[1, 1] for _ in xrange(len(nums))]  # {length, number} pair
        for i in xrange(len(nums)):
            for j in xrange(i):
                if nums[i] > nums[j]:
                    if dp[i][0] == dp[j][0]+1:
                        dp[i][1] += dp[j][1]
                    elif dp[i][0] < dp[j][0]+1:
                        dp[i] = [dp[j][0]+1, dp[j][1]]
            if max_len == dp[i][0]:
                result += dp[i][1]
            elif max_len < dp[i][0]:
                max_len = dp[i][0]
                result = dp[i][1]
        return result

# Time:  O(n^2)
# Space: O(n)
class Solution2:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n =len(nums)
        if n == 0 : 
            return 0

        lengths = [1] * n  # lengths[i] = length of LIS ending at index i
        counts = [1] * n   # counts[i] = number of LIS ending at index i
        
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if lengths[j]+1 > lengths[i]:
                        lengths[i] = lengths[j]+1
                        counts[i] = counts[j]
                    elif lengths[j] + 1 == lengths[i]:
                        counts[i] += counts[j]
        max_len = max(lengths)
        return sum(c for l, c in zip(lengths, counts) if l == max_len)
