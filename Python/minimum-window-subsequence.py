# Time:  O(S * T)
# Space: O(S)

class Solution(object):
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        dp = [[None for _ in xrange(len(S))] for _ in xrange(2)]
        for i, c in enumerate(S):
            if c == T[0]:
                dp[0][i] = i
                
        for j in xrange(1, len(T)):
            prev = None
            dp[j%2] = [None] * len(S)
            for i, c in enumerate(S):
                if prev is not None and c == T[j]:
                    dp[j%2][i] = prev
                if dp[(j-1)%2][i] is not None:
                    prev = dp[(j-1)%2][i]

        start, end = 0, len(S)
        for j, i in enumerate(dp[(len(T)-1)%2]):
            if i >= 0 and j-i < end-start:
                start, end = i, j
        return S[start:end+1] if end < len(S) else ""
