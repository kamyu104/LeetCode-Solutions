# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def maxTotal(self, nums, s):
        """
        :type nums: List[int]
        :type s: str
        :rtype: int
        """
        result = i = 0
        while i < len(nums):
            if s[i] == '0':
                i += 1
                continue
            result += nums[i-1] if i-1 >= 0 else 0
            mn = nums[i-1] if i-1 >= 0 else 0
            j = i
            while j < len(s) and s[j] == '1':
                result += nums[j]
                mn = min(mn, nums[j])
                j += 1
            result -= mn
            i = j
        return result


# Time:  O(n)
# Space: O(1)
# dp
class Solution2(object):
    def maxTotal(self, nums, s):
        """
        :type nums: List[int]
        :type s: str
        :rtype: int
        """
        NEG_INF = float("-inf")
        dp = [NEG_INF]*2
        dp[0] = 0
        for i in xrange(len(s)):
            new_dp = [NEG_INF]*2
            if s[i] == '0':
                new_dp[0] = max(dp)
            else:
                new_dp[1] = max(dp)+nums[i]
                if i-1 >= 0:
                    new_dp[0] = dp[0]+nums[i-1]
            dp = new_dp
        return max(dp)
