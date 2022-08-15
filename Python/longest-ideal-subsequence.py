# Time:  O(n)
# Space: O(1)

# dp
class Solution(object):
    def longestIdealString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        dp = [0]*26
        for c in s:
            x = ord(c)-ord('a')
            dp[x] = max(dp[i] for i in xrange(max(x-k, 0), min(x+k+1, 26)))+1
        return max(dp)
