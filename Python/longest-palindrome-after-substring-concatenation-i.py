# Time:  O(n * m)
# Space: O(n + m)

# manacher's algorithm, dp
class Solution(object):
    def longestPalindrome(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        def manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P

        def longest_palindrome(s):
            result = [0]*(len(s)+1)
            P = manacher(s)
            for i in xrange(1, len(P)-1):
                result[(i-P[i])//2] = P[i]
            return result

        t = t[::-1]
        p1 = longest_palindrome(s)
        p2 = longest_palindrome(t)
        result = 0
        dp = [[0]*(len(t)+1) for _ in xrange(len(s)+1)]
        for i in xrange(len(s)):
            for j in xrange(len(t)):
                dp[i+1][j+1] = dp[i][j]+2 if s[i] == t[j] else 0
                result = max(result, dp[i+1][j+1]+max(p1[i+int(s[i] == t[j])] , p2[j+int(s[i] == t[j])]))
        return result
