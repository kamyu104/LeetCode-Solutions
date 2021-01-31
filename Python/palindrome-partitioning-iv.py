# Time:  O(n)
# Space: O(n)

class Solution(object):
    def checkPartitioning(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def modified_manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            dp1 = [False]*len(s)  # dp1[i]: s[:i] is a palindromic string
            dp2 = [False]*len(s)  # dp2[i]: s[:i+1] is composed of 2 palindromic strings
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    if dp1[i-1-P[i]]:
                        dp2[i+1+P[i]] = True
                    P[i] += 1
                if i+1+P[i] == len(s)-1 and dp2[i-1-P[i]]:
                    return True
                if i-1-P[i] == 0:
                    dp1[i+1+P[i]] = True
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return False

        return modified_manacher(s)


# Time:  O(n^2)
# Space: O(n)
class Solution(object):
    def checkPartitioning(self, s):
        """
        :type s: str
        :rtype: bool
        """        
        dp = [[False]*len(s) for _ in xrange(len(s))]
        for i in reversed(xrange(len(s))):
            for j in xrange(i, len(s)):
                if s[i] == s[j] and (j-i < 2 or dp[i+1][j-1]):
                    dp[i][j] = True
        for i in xrange(1, len(s)):
            for j in xrange(i+1, len(s)):
                if dp[0][i-1] and dp[i][j-1] and dp[j][-1]:
                    return True
        return False
