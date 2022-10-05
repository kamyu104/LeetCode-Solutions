# Time:  O(n^2)
# Space: O(n)

# dp
class Solution(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        if all(x == s[0] for x in s):
            return len(s)
        dp2 = [[0]*(len(s)+1) for i in xrange(2)]  # dp2[i%2][j]: max prefix length of s[i:] and s[j:]
        dp = [1]*len(s)  # dp[i]: max operation count of s[i:]
        for i in reversed(xrange(len(s)-1)):
            for j in xrange(i+1, len(s)):
                dp2[i%2][j] = dp2[(i+1)%2][j+1]+1 if s[j] == s[i] else 0
                if dp2[i%2][j] >= j-i:
                    dp[i] = max(dp[i], dp[j]+1)
        return dp[0]


# Time:  O(n^2)
# Space: O(n)
# dp, kmp algorithm
class Solution2(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        def getPrefix(pattern, start):
            prefix = [-1]*(len(pattern)-start)
            j = -1
            for i in xrange(1, len(pattern)-start):
                while j != -1 and pattern[start+j+1] != pattern[start+i]:
                    j = prefix[j]
                if pattern[start+j+1] == pattern[start+i]:
                    j += 1
                prefix[i] = j
            return prefix

        if all(x == s[0] for x in s):
            return len(s)
        dp = [1]*len(s)  # dp[i]: max operation count of s[i:]
        for i in reversed(xrange(len(s)-1)):
            prefix = getPrefix(s, i)  # prefix[j]+1: longest prefix suffix length of s[i:j+1]
            for j in xrange(1, len(prefix), 2):
                if 2*(prefix[j]+1) == j+1:
                    dp[i] = max(dp[i], dp[i+(prefix[j]+1)]+1)
        return dp[0]


# Time:  O(n^2)
# Space: O(n)
# dp, rolling hash
class Solution3(object):
    def deleteString(self, s):
        """
        :type s: str
        :rtype: int
        """
        MOD, P = 10**9+7, (113, 109)
        def hash(i, j):
            return [(prefix[idx][j+1]-prefix[idx][i]*power[idx][j-i+1])%MOD for idx in xrange(len(P))]

        if all(x == s[0] for x in s):
            return len(s)

        power = [[1] for _ in xrange(len(P))]
        prefix = [[0] for _ in xrange(len(P))]
        for x in s:
            for idx, p in enumerate(P):
                power[idx].append((power[idx][-1]*p)%MOD)
                prefix[idx].append((prefix[idx][-1]*p+(ord(x)-ord('a')))%MOD)
        dp = [1]*len(s)  # dp[i]: max operation count of s[i:]
        for i in reversed(xrange(len(s)-1)):
            for j in xrange(1, (len(s)-i)//2+1):
                if hash(i, i+j-1) == hash(i+j, i+2*j-1):
                    dp[i] = max(dp[i], dp[i+j]+1)
        return dp[0]
