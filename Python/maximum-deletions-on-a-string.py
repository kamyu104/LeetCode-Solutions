# Time:  O(n^2)
# Space: O(n)

# dp, lps algorithm
class Solution(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        def getPrefix(pattern, start):
            prefix = [-1]*(len(pattern)-start)
            j = -1
            for i in xrange(1, len(pattern)-start):
                while j > -1 and pattern[start+j+1] != pattern[start+i]:
                    j = prefix[j]
                if pattern[start+j+1] == pattern[start+i]:
                    j += 1
                prefix[i] = j
            return prefix

        if all(x == s[0] for x in s):
            return len(s)
        dp = [1]*len(s)  # dp[i]: max operations of s[i:]
        for i in reversed(xrange(len(s)-1)):
            prefix = getPrefix(s, i)  # prefix[j]+1: longest prefix suffix length of s[i:j+1]
            for j in xrange(1, len(prefix), 2):
                if 2*(prefix[j]+1) == j+1:
                    dp[i] = max(dp[i], dp[i+(prefix[j]+1)]+1)
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
