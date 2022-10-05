# Time:  O(n^2)
# Space: O(n)

# dp, lps algorithm
class Solution(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        def longest_prefix_suffix(i):  # Time: O(n), Space: O(n)
            lps = [0]*(len(s)-i)
            l = 0
            for j in xrange(1, len(lps)):
                while l != 0 and s[i+l] != s[i+j]:
                    l = lps[l-1]
                if s[i+j] == s[i+l]:
                    l += 1
                lps[j] = l
            return lps

        if all(x == s[0] for x in s):
            return len(s)
        dp = [1]*len(s)  # dp[i]: max operations of s[i:]
        for i in reversed(xrange(len(s)-1)):
            lps = longest_prefix_suffix(i)  # lps[j]: longest prefix suffix length of s[i:j+1]
            for j in xrange(1, len(lps), 2):
                if 2*lps[j] == j+1:
                    dp[i] = max(dp[i], dp[i+lps[j]]+1)
        return dp[0]


# Time:  O(n^2)
# Space: O(n^2)
# dp
class Solution2(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        if all(x == s[0] for x in s):
            return len(s)
        dp = [[0]*(len(s)+1) for i in xrange(len(s)+1)]  # dp[i][j]: max prefix length of s[i:] and s[j:]
        dp2 = [1]*len(s)  # dp2[i]: max operation count of s[i:]
        for i in reversed(xrange(len(s)-1)):
            for j in xrange(i+1, len(s)):
                if s[j] == s[i]:
                    dp[i][j] = dp[i+1][j+1]+1
                if dp[i][j] >= j-i:
                    dp2[i] = max(dp2[i], dp2[j]+1)
        return dp2[0]
