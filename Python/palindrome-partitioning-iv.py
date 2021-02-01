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
            dp = [0]*len(s)  # dp[i]: s[:i] is composed of dp[i] palindromic strings
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    if dp[i-1-P[i]]:
                        dp[(i+1+P[i])+1] = dp[i-1-P[i]]+1
                    P[i] += 1
                if i+1+P[i] == len(s)-1 and dp[(i-1-P[i])+1] == 2:
                    return True
                if i-1-P[i] == 0:
                    dp[i+1+P[i]] = 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return False

        return modified_manacher(s)


# Time:  O(n^2)
# Space: O(n^2)
class Solution2(object):
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
        for i in xrange(1, len(s)-1):
            if not dp[0][i-1]:
                continue
            for j in xrange(i+1, len(s)):
                if not dp[j][-1]:
                    continue
                if dp[i][j-1]:
                    return True
        return False
